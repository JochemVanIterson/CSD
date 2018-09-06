# ------------------------------------------- Imports ------------------------------------------- #
import os, fnmatch
import simpleaudio as sa

# ------------------------------------------- Functions ----------------------------------------- #
def playFile(filename):
    wave_obj = sa.WaveObject.from_wave_file(filename)
    play_obj = wave_obj.play()
    play_obj.wait_done()

def repeatPlay(chosenfile, times):
    while(times>0):
        print("playing")
        playFile(chosenfile)
        times -= 1

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

print("Done playing. Goodby!!")
