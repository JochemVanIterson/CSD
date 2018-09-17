# command: python3 playsound.py 4 1 .5 1.5 1 120

# ------------------------------------------- Imports ------------------------------------------- #
import os, fnmatch
import sys
import simpleaudio as sa
import time

# ------------------------------------------- Variables ----------------------------------------- #
# ['playsound.py', '4', '1', '.5', '1.5', '1', '150']
numPlaybackTimes = int(sys.argv[1]) # take second var from array
sequence = sys.argv[2:2+numPlaybackTimes] # take from third var plus 'numPlaybackTimes' from array
BPM = int(sys.argv[-1]) # take last from array
print('numPlaybackTimes', numPlaybackTimes)
print('sequence', str(sequence))
print('BPM', BPM)

# ------------------------------------------- Functions ----------------------------------------- #
def playFile(filename):
    wave_obj = sa.WaveObject.from_wave_file(filename)
    play_obj = wave_obj.play()

def repeatPlay(chosenfile, times):
    while(times>0):
        for note in sequence:
            playFile(chosenfile)
            time.sleep(note2time(float(note)))
        times -= 1

def note2time(note):
    return (60./BPM)*note

# ------------------------------------------- File list ----------------------------------------- #
audiofiles = []
listOfFiles = os.listdir('.')
pattern = "*.wav"
for entry in listOfFiles:
    if fnmatch.fnmatch(entry, pattern):
        audiofiles.append(entry)

# ------------------------------------------- UI questions -------------------------------------- #
for idx, file in enumerate(audiofiles):
    print('('+str(idx)+") "+file)

fileindex = int(input("Which file would you like to play? "))
while(fileindex<0 or fileindex>=len(audiofiles)): # ---------- Range check ---------- #
    print("Not in range. Choose a file between 0 and "+str(len(audiofiles)))
    fileindex = int(input("Which file would you like to play? "))

times = int(input("How many times? "))

# ------------------------------------------- Playback ------------------------------------------ #
chosenfile = audiofiles[fileindex]
repeatPlay(chosenfile, times)

print("Done playing. Goodbye!!")
