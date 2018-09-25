# command: python3 playsound.py < input.txt

# ------------------------------------------- Imports ------------------------------------------- #
import os, fnmatch
import sys
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
fileindex = int(input("Which file would you like to play? "))
while(fileindex<0 or fileindex>=len(audiofiles)): # ---------- Range check ---------- #
    print("Not in range. Choose a file between 0 and "+str(len(audiofiles)))
    fileindex = int(input("Which file would you like to play? "))

# ----- repeatTimes ----- #
timesStr = input("How many times? (default = 5) ")
if(timesStr==""): times=5
else: times=int(timesStr)

# ----- BPM ----- #
bpmStr = input("BPM? (default = 120) ")
if(bpmStr==""): bpm=120
else: bpm=int(bpmStr)

# ----- Number of notes ----- #
numPlaybackTimes = int(input("How many notes? ")) # take second var from array

# ----- Notes ----- #
sequence = []
for note in range(0, numPlaybackTimes):
    sequence.append(float(input("("+str(note)+") ")))

# ------------------------------------------- Playback ------------------------------------------ #
chosenfile = audiofiles[fileindex]
wave_obj = sa.WaveObject.from_wave_file(chosenfile)
repeatPlay(wave_obj, times)

print("Done playing. Goodbye!!")
