# python3 irrbeat.py

# --------------------------------------------------------------------------------------------------------- #
# ------------------------------------------------ INIT --------------------------------------------------- #
# --------------------------------------------------------------------------------------------------------- #

# ------------------------------------------- Imports ------------------------------------------- #
import os, fnmatch
import simpleaudio as sa
import time
import random

# ------------------------------------------- Functions ----------------------------------------- #
def listAudiofilesBuilder(dir):
    audiofiles = []
    listOfFiles = os.listdir(dir)
    pattern = "*.wav"
    for entry in listOfFiles:
        if fnmatch.fnmatch(entry, pattern):
            audiofiles.append(entry)
    return audiofiles

# -------- UI -------- #
def UI_BPM():
    while True:
        try:
            bpmStr = input("BPM? (default = "+str(bpm)+") ")
            if(bpmStr==""):
                # bpm=120 # delault value
                return bpm
            else:
                return int(bpmStr)
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

    def status(self):
        print("\n------------------- BeatGenerator Status -------------------")
        print("beatPerMeasure: ", self.beatPerMeasure)
        print("beatUnit:       ", self.beatUnit)
        print("beat16Amount:   ", self.beat16Amount)
        print("positions:      ", self.positions)
        print("beatAccents:    ", self.beatAccents)
        print("notesPerAccent: ", self.notesPerAccent)
        print("accentMap:      ", self.accentMap)

# ------------------------------------------- Vars ---------------------------------------------- #
bpm = 110
measure = ''
possibleMeasures = ['5/4', '5/8', '7/8', 'other']
audioFilePath = "../pythonExamples/audio/01_audioFiles/audioFiles/" # "." for current folder
listAudiofiles = listAudiofilesBuilder(audioFilePath)

global sampleHigh, sampleMid, sampleLow

# --------------------------------------------------------------------------------------------------------- #
# ------------------------------------------------ Programm ----------------------------------------------- #
# --------------------------------------------------------------------------------------------------------- #

# ------------------------------------------- UI questions -------------------------------------- #
# ---------- BPM -------------- #
bpm = UI_BPM()

# ---------- Measure ---------- #
measure = UI_measure()

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
print("")
print("BPM:", bpm)
print("measure:", measure)

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

generator = BeatGenerator(measure)
generator.createBeat()