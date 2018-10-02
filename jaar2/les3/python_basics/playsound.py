# command: python3 playsound.py < input.txt

# ------------------------------------------- Imports ------------------------------------------- #
import os, fnmatch
import simpleaudio as sa
import time

# ------------------------------------------- Functions ----------------------------------------- #
def playFile(wave_obj):
    play_obj = wave_obj.play()

def repeatPlay(wave_obj, times):
    while(times>0):
        for note in sequence:
            playFile(wave_obj)
            time.sleep(note2time(float(note)))
        times -= 1

def note2time(note):
    return (60./bpm)*note

def durationsToTimestamps16th(inputList):
    timestampsList16 = []
    currentTimestamp = 0
    for itm in inputList:
        timestampsList16.append(currentTimestamp)
        currentTimestamp += int(itm*4)
    return timestampsList16

def timestamps16thToTimestamps(inputList, bpm):
    sixteenthNoteDuration = (60./bpm)*.25
    timestamps = []
    for timestamp in inputList:
        timestamps.append(timestamp * sixteenthNoteDuration)
    return timestamps

# ------------------------------------------- File list ----------------------------------------- #
audiofiles = []
listOfFiles = os.listdir('.')
pattern = "*.wav"
for entry in listOfFiles:
    if fnmatch.fnmatch(entry, pattern):
        audiofiles.append(entry)

# ------------------------------------------- UI questions -------------------------------------- #
# ----- Show list possible files ----- #
for idx, file in enumerate(audiofiles):
    print('('+str(idx)+") "+file)

# ----- Select file ----- #
while True:
    try:
        fileindex = int(input("Which file would you like to play? "))
        if(fileindex<0 or fileindex>=len(audiofiles)):
            print("Not in range. Choose a file between 0 and "+str(len(audiofiles)))
        else:
            break
    except ValueError:
        print("Please fill in the number of the selected audio file.")

# ----- repeatTimes ----- #
while True:
    try:
        timesStr = input("How many times? (default = 4) ")
        if(timesStr==""):
            times=4 # delault value
            break
        else:
            times=int(timesStr)
            break
    except ValueError:
        print("The given value wasn't a number")

# ----- BPM ----- #
while True:
    try:
        bpmStr = input("BPM? (default = 120) ")
        if(bpmStr==""):
            bpm=120 # delault value
            break
        else:
            bpm=int(bpmStr)
            break
    except ValueError:
        print("The given value wasn't a number")

# ----- Number of notes ----- #
while True:
    try:
        numPlaybackTimes = int(input("How many notes? "))
        break
    except ValueError:
        print("The given value wasn't a number")

# ----- Notes ----- #
sequence = []
for note in range(0, numPlaybackTimes):
    sequence.append(float(input("("+str(note)+") ")))

repeatedSequence = []
for x in range(0, times):
    repeatedSequence += sequence
timestampsList16 = durationsToTimestamps16th(repeatedSequence)
timestampsList = timestamps16thToTimestamps(timestampsList16, bpm)
print(timestampsList)

# ------------------------------------------- Playback ------------------------------------------ #
chosenfile = audiofiles[fileindex]
wave_obj = sa.WaveObject.from_wave_file(chosenfile)
repeatPlay(wave_obj, times)

print("Done playing. Goodbye!!")
