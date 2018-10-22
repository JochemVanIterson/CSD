from midiutil import MIDIFile

durationList1 = [1, 0.5, 0.5, 1, 0.25, 0.5, 0.25]
durationList2 = [1, 0.25, 0.5, 0.25, 1, 0.5, 0.5]
durationList3 = [0.5, 0.25, 1, 0.5, 0.5, 1, 0.25]
bpm = 120

class midiExport:
    global __MyMIDI
    global track, channel, volume
    def __init__(self, tempo):
        self.track    = 0
        self.channel  = 10
        self.volume    = 100  # 0-127, as per the MIDI standard
        self.__MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track is created automatically)
        self.__MyMIDI.addTempo(self.track, 0, tempo)

    def addNotes(self, durationList, midiNote):
        currentTime = 0
        for duration in durationList:
            self.__MyMIDI.addNote(self.track, self.channel, midiNote, currentTime, .25, self.volume)
            currentTime += duration

    def save(self, filename):
        with open(filename, "wb") as output_file:
            self.__MyMIDI.writeFile(output_file)

exporter = midiExport(bpm)
exporter.addNotes(durationList1, 36)
exporter.addNotes(durationList2, 38)
exporter.addNotes(durationList3, 42)
filename = input("Doe mij filenaam geven! ")
exporter.save(filename)
