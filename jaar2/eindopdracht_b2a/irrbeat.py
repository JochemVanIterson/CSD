# python3 irrbeat.py < input.txt

# --------------------------------------------------------------------------------------------------------- #
# ------------------------------------------------ INIT --------------------------------------------------- #
# --------------------------------------------------------------------------------------------------------- #

# ------------------------------------------- Imports ------------------------------------------- #
import os, fnmatch
import simpleaudio as sa
import time
import random
import math
from midiutil import MIDIFile # https://pypi.org/project/MIDIUtil/

# ------------------------------------------- Functions ----------------------------------------- #
def listAudiofilesBuilder(dir):
    audiofiles = []
    listOfFiles = os.listdir(dir)
    pattern = "*.wav"
    for entry in listOfFiles:
        if fnmatch.fnmatch(entry, pattern):
            audiofiles.append(entry)
    return audiofiles

def playSequence(timestampsRaw):
    timestamps = timestampsRaw.copy()
    timestamp = timestamps.pop(0) # retrieve first timestamp
    startTime = time.time() # retrieve the startime: current time
    keepPlaying = True
    # play the sequence
    while keepPlaying:
        currentTime = time.time() # retrieve current time
        if(currentTime - startTime >= timestamp[0]): # check if the timestamp's time is passed
            if 'l' in timestamp: # Play low sample
                sampleLow.play()
            if 'm' in timestamp: # Play mid sample
                sampleMid.play()
            if 'h' in timestamp: # Play high sample
                sampleHigh.play()

            if timestamps: # if there are timestamps left in the timestamps list
                timestamp = timestamps.pop(0) # retrieve the next timestamp
            else:
                keepPlaying = False # list is empty, stop loop
        else:
            time.sleep(0.001) # wait for a very short moment

# -------- UI -------- #
def UI_BPM():
    while True:
        try:
            bpmStr = input("BPM? (default = "+str(bpm)+") ")
            if(bpmStr==""):
                return bpm
            else:
                return int(bpmStr)
        except ValueError:
            print("The given value wasn't a number")
def UI_repeat():
    while True:
        try:
            repeatTimesStr = input("Repeat? (default = "+str(repeatTimes)+") ")
            if(repeatTimesStr==""):
                return repeatTimes
            else:
                return int(repeatTimesStr)
        except ValueError:
            print("The given value wasn't a number")
def UI_measure():
    for index, measureoption in enumerate(possibleMeasures):
        print('('+str(index)+')', measureoption)
    while True:
        try:
            measureInput = possibleMeasures[int(input("Measure? "))]
            if measureInput is 'other':
                while True:
                    measureRaw = input("fill in measure: (n/n) ")
                    if '/' not in measureRaw:
                        print("Wrong format, use (n/n)")
                    elif len(measureRaw.split('/')) is not 2:
                        print("Too many '/', use (n/n)")
                    else:
                        return measureRaw
                break
            else:
                return measureInput
                break
        except ValueError:
            print("The given value wasn't a number")
        except IndexError:
            print("Index out of range")
def UI_randomSample():
    while True:
        try:
            randSamplesStr = input("Randomize samples? (yes/no) (default = yes) ")
            if (randSamplesStr == "") or (randSamplesStr.lower()=="yes"):
                return True
            elif randSamplesStr.lower()=="no":
                return False
            else:
                print("Wrong input")
        except ValueError:
            print("Wrong input")
def UI_selectSample(name):
    while True:
        try:
            sampleInput = listAudiofiles[int(input(name+"? "))]
            if sampleInput is 'other':
                while True:
                    sampleRaw = input("filepath: ")
                    if not os.path.isfile(sampleRaw):
                        print("File doesn't exist")
                    elif not sampleRaw.endswith(('.wav', '.mp3', '.aif', '.aiff')):
                        print("Not an audio file")
                    else:
                        return sampleRaw
            else:
                return audioFilePath+sampleInput
        except ValueError:
            print("The given value wasn't a number")
        except IndexError:
            print("Index out of range")

class SamplePlayback:
    def __init__(self, filepath):
        self.wave_obj = sa.WaveObject.from_wave_file(filepath)

    def play(self, wait=False):
        play_obj = self.wave_obj.play()
        if wait:
            play_obj.wait_done()
        return play_obj
class BeatGenerator:
    global beatUnit, beatPerMeasure, beat16Amount, positions, beatAccents, notesPerAccent, accentMap
    global lowBeat, midBeat, highBeat
    def __init__(self, measure):
        self.beatPerMeasure = int(measure.split('/')[0])
        self.beatUnit = int(measure.split('/')[1])
        self.beat16Amount = 1/(self.beatUnit/16) # convert unit to amount of 16th
        self.positions = self.beatPerMeasure*self.beat16Amount # set total amount of 16th
        self.beatAccents = random.randint(2, 4)
        self.notesPerAccent = int(self.positions/self.beatAccents)
        self.accentMap = self.__createAccentMap()

    def __createAccentMap(self):
        outputarray = []
        nthAccent = 0
        for i in range(0, int(self.positions)):
            accentPosition = i%self.notesPerAccent
            if(accentPosition==0):
                nthAccent+=1
            if(nthAccent>self.beatAccents):
                accentPosition+=self.notesPerAccent
            outputarray.append(accentPosition)
        return outputarray
    def __createLow(self):
        outputarray = []
        for i, value in enumerate(self.accentMap):
            randomvalue = random.uniform(0, 1.0)
            if (value==0):
                if (randomvalue<0.8):
                    outputarray.append(i)
            elif (value==2) :
                if (randomvalue<0.4):
                    outputarray.append(i)
            elif (randomvalue<0.1):
                outputarray.append(i)
        return outputarray
    def __createMid(self):
        outputarray = []
        for i, value in enumerate(self.accentMap):
            randomvalue = random.uniform(0, 1.0)
            if (value==2):
                if (randomvalue<0.7):
                    outputarray.append(i)
            elif (value==0) :
                if (randomvalue<0.5):
                    outputarray.append(i)
            elif (randomvalue<0.2):
                outputarray.append(i)
        return outputarray
    def __createHigh(self):
        outputarray = []
        for i, value in enumerate(self.accentMap):
            randomvalue = random.uniform(0, 1.0)
            if (randomvalue<0.7):
                outputarray.append(i)
        return outputarray
    def __buildEventList(self, times, lowBeat, midBeat, highBeat):
        events = [[y] for y in range(int(self.positions)*times)]
        for repeatTime in range(0, times):
            offset = int(repeatTime*self.positions)
            for lowIndex in lowBeat:
                events[offset+lowIndex].append("l")
            for midIndex in midBeat:
                events[offset+midIndex].append("m")
            for highIndex in highBeat:
                events[offset+highIndex].append("h")
        return events
    def __eventsToTimestamps(self, inputList, bpm):
        sixteenthNoteDuration = (60./bpm)*.25
        timestamps = []
        for event in inputList:
            if(len(event)>1):
                newEvent = [event[0]*sixteenthNoteDuration]
                newEvent.extend(event[1:])
                timestamps.append(newEvent)
        return timestamps

    def createBeat(self):
        self.lowBeat = self.__createLow()
        self.midBeat = self.__createMid()
        self.highBeat = self.__createHigh()
        events = self.__buildEventList(1, self.lowBeat, self.midBeat, self.highBeat)
        timestamps = self.__eventsToTimestamps(events, bpm)
        return events, timestamps
    def createRepeatedStamps(self, times):
        events = self.__buildEventList(times, self.lowBeat, self.midBeat, self.highBeat)
        timestamps = self.__eventsToTimestamps(events, bpm)
        return events, timestamps
    def measureInfo(self):
        return self.beatUnit, self.beatPerMeasure, self.beat16Amount, self.positions, self.beatAccents, self.notesPerAccent, self.accentMap
    def status(self):
        print("\n------------------- BeatGenerator Status -------------------")
        print("beatPerMeasure: ", self.beatPerMeasure)
        print("beatUnit:       ", self.beatUnit)
        print("beat16Amount:   ", self.beat16Amount)
        print("positions:      ", self.positions)
        print("beatAccents:    ", self.beatAccents)
        print("notesPerAccent: ", self.notesPerAccent)
        print("accentMap:      ", self.accentMap)
class MidiExport:
    global midiExportFile
    midinote_l = 36
    midinote_m = 38
    midinote_h = 42

    def __init__(self, generator):
        self.midiExportFile = MIDIFile(2)
                                  # (track, time, tempo)
        self.midiExportFile.addTempo(1000, 0, bpm)
        numerator = generator.beatPerMeasure
        denominator = int(math.log(generator.beatUnit, 2))
        clocksPerTick = int(24*(4/generator.beatUnit))
        self.midiExportFile.addTimeSignature(1000, 0, numerator, denominator, clocksPerTick)

    def export(self, sequence, filename):
        sixteenthNoteDuration = (60./bpm)*.25
        for event in sequence:
            print(event[1:])
            if(len(event)>1):
                for sound in event[1:]:
                    if sound is "l":
                        pitch = self.midinote_l
                    elif sound is "m":
                        pitch = self.midinote_m
                    elif sound is "h":
                        pitch = self.midinote_h
                                             # (track, channel, pitch, time, duration, volume)
                    self.midiExportFile.addNote(0, 9, pitch, event[0]*.25, .25, 100)

        with open(filename+".mid", "wb") as output_file:
            self.midiExportFile.writeFile(output_file)
# ------------------------------------------- Vars ---------------------------------------------- #
bpm = 110
measure = ''
repeatTimes = 4
possibleMeasures = ['5/4', '5/8', '7/8', '8/8', '9/8', 'other']
audioFilePath = "../pythonExamples/audio/01_audioFiles/audioFiles/" # "." for current folder
listAudiofiles = listAudiofilesBuilder(audioFilePath)

global sampleHigh, sampleMid, sampleLow

# --------------------------------------------------------------------------------------------------------- #
# ------------------------------------------------ Programm ----------------------------------------------- #
# --------------------------------------------------------------------------------------------------------- #

# ------------------------------------------- UI questions -------------------------------------- #
bpm = UI_BPM() # ------------------ BPM -------------- #
repeatTimes = UI_repeat() # ------- Repeat ----------- #
measure = UI_measure() # ---------- Measure ---------- #

# ---------- Samples ---------- #
if UI_randomSample():
    removableList = listAudiofiles.copy();
    sampleNameHigh = audioFilePath+removableList.pop(random.randint(0, len(removableList))-1);
    sampleNameMid  = audioFilePath+removableList.pop(random.randint(0, len(removableList))-1);
    sampleNameLow  = audioFilePath+removableList.pop(random.randint(0, len(removableList))-1);
else:
    listAudiofiles.append("other")
    for index, audioFile in enumerate(listAudiofiles):
        print('('+str(index)+')', audioFile)
    sampleNameHigh = UI_selectSample('sampleHigh');
    sampleNameMid  = UI_selectSample('sampleMid');
    sampleNameLow  = UI_selectSample('sampleLow');

# ---------- Open samples ----- #
sampleHigh = SamplePlayback(sampleNameHigh)
sampleMid  = SamplePlayback(sampleNameMid)
sampleLow  = SamplePlayback(sampleNameLow)

# ------------------------------------------- Chosen Values ------------------------------------- #
print("\n---------------------- Chosen values -----------------------")
print("BPM:    ", bpm)
print("Repeat: ", repeatTimes)
print("Measure:", measure)

# preview of chosen samples
print("Samples:")
print("  sampleHigh:", sampleNameHigh)
sampleHigh.play(True)
time.sleep(.4)
print("  sampleMid: ", sampleNameMid)
sampleMid.play(True)
time.sleep(.4)
print("  sampleLow: ", sampleNameLow)
sampleLow.play(True)
time.sleep(.4)

# init the beat generator with the chosen settings
generator = BeatGenerator(measure)
generator.status()

while(True): # Loop for repeated creation and playback of beats
    print("\n---------------------- Creating beat -----------------------")
    beat = generator.createBeat()
    repeatedBeat = generator.createRepeatedStamps(repeatTimes)
    playSequence(repeatedBeat[1])
    print("(r)  Play again")
    print("(y)  Convert to Midi and create new beat")
    print("(yq) Convert to Midi and quit program")
    print("(n)  Create new beat")
    print("(q)  Quit program")

    while(True): # Action checkup
        action = input("Save? ")
        if(action=='r'):
            playSequence(repeatedBeat[1])
        elif(action=='y' or action=='yq' or action=='n' or action=='q'):
            break
        else:
            print("unknown option")
    if(action=='y'):
        print("Saving...")
        print(beat[0])
        midiExporter = MidiExport(generator)
        filename = input("Filename: ")
        midiExporter.export(beat[0], filename)
        # TODO: convert beat to midi
    if(action=='yq'):
        print("Saving...")
        print(beat[0])
        midiExporter = MidiExport(generator)
        filename = input("Filename: ")
        midiExporter.export(beat[0], filename)
        # TODO: convert beat to midi
        break
    if(action=='q'):
        break

# print(beat)
print("Quit program")
time.sleep(.5)
