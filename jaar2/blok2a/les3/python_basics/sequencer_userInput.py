import simpleaudio as sa
import time
import random

"""
An example project in which a rhythmical sequence (one measure, 1 sample) is played.
  - Sixteenth note is the smallest used note duration.
  - One meassure, time signature: 3 / 4

Instead of using steps to iterate through a sequence, we are checking the time.
We will trigger events based on a timestamp.

------ HANDS-ON TIPS ------
- Run the code, read the code and answer the following question:
  - This script transforms a list of 'sixteenth notes timestamps' into a list of
    regular timestamps.
    In the playback loop, the time difference (currentTime minus startTime)
    is compared to the upcomming timestamp.
    Why is this a more accurate method then the methods used in the examples
    "04_randomNoteDuration.py" and "05_oneSampleSequenceSteps.py"?
    Notate your answer below this line (Dutch is allowed)!
        De computer clock stelt je in staat meerdere samples te triggeren los van de lopende delay

- Alter the code:
  Currently one sample is played. Add another sample to the script.
  When a sample needs to be played, choose one of the two samples
  randomly.
  (See the hint about the random package in script "02_timedPlayback".)

- Alter the code:
  Currently the sequence is only played once.
  Alter the code to play it multiple times.
  hint: The timestamps list is emptied using the pop() function.
  (multiple possible solutions)

"""

# load 1 audioFile and store it into a list
# note: using a list taking the next step into account: using multiple samples
samples = [sa.WaveObject.from_wave_file("Dog2.wav")]#, sa.WaveObject.from_wave_file("testfile 1.wav"), sa.WaveObject.from_wave_file("testfile 2.wav")]
print(len(samples))
# set bpm
bpm = 120
# calculate the duration of a quarter note
quarterNoteDuration = 60 / bpm
# calculate the duration of a sixteenth note
sixteenthNoteDuration = quarterNoteDuration / 4.0

repeatTimes = 2;

# create a list to hold the timestamps
timestamps = []
# create a list with ‘note timestamps' in 16th at which we should play the sample
timestamps16th = [0, 2, 4, 8, 11]
def buildTimestamps(timestamps16th):
    # transform the sixteenthTimestamps to a timestamps list with time values
    for timestamp in timestamps16th:
        timestamps.append(timestamp * sixteenthNoteDuration)

buildTimestamps(timestamps16th)

# NOTE: pop(0) returns and removes the element at index 0
timestamp = timestamps.pop(0) # retrieve first timestamp
startTime = time.time() # retrieve the startime: current time
repeatTimes-=1
keepPlaying = True
# play the sequence
while keepPlaying:
    currentTime = time.time() # retrieve current time
    if(currentTime - startTime >= timestamp): # check if the timestamp's time is passed
        samples[random.randint(0, len(samples)-1)].play() # play sample
        if timestamps: # if there are timestamps left in the timestamps list
            timestamp = timestamps.pop(0) # retrieve the next timestamp
        elif repeatTimes>0:
            buildTimestamps(timestamps16th)
            print("repeat")
            timestamp = timestamps.pop(0)
            startTime = time.time()
            repeatTimes-=1
        else:
            keepPlaying = False # list is empty, stop loop
    else:
        time.sleep(0.001) # wait for a very short moment
time.sleep(2)
