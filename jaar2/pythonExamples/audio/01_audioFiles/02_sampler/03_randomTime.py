import simpleaudio as sa
import time
import random

"""
An example project in which three wav files are played after eachother with a
break in between of a random duration.
Used durations are: 0.125, 0.25 and 0.5 seconds

------ HANDS-ON TIPS ------
- Alter the code:
  Add a noteDurations list, with the numbers 0.25, 0.5, 1.0. These values stand
  for a sixteenth, eighth and quarter note.
  Add a bpm value to the project and calculate the corresponding timeIntervals
  accordingly. Add these values to the timeIntervals list, instead of its
  current values.

- Alter the code:
  Write a function around the playback forloop, which takes two arguments:
  - a list with samples
  - a list with timeIntervals
  Use this function.
"""

def note2time(note):
    return (60./BPM)*note

# load 3 audioFiles into a list
samples = [sa.WaveObject.from_wave_file("../audioFiles/Pop.wav"),
              sa.WaveObject.from_wave_file("../audioFiles/Laser1.wav"),
              sa.WaveObject.from_wave_file("../audioFiles/Dog2.wav")]

# create a list to hold the timeIntervals 0.25, 0.5, 1.0
timeIntervals = [0.25, 0.5, 1]
noteDurations = [0.25, 0.5, 1.0]
# play samples and wait in between (random duration)
for sample in samples:
  sample.play()
  # ----------------------------- notelength ----------------------------- #
  notelengthIndex = random.randint(0, 2)
  notelength = noteDurations[notelengthIndex]
  print("notelength: " + str(notelength) + " seconds.")
  time.sleep(notelength)

  # ----------------------------- timeIntervals -------------------------- #
  timeIntervalIndex = random.randint(0, 2)
  timeInterval = timeIntervals[timeIntervalIndex]
  print("timeInterval: " + str(timeInterval) + " seconds.")
  time.sleep(timeInterval)
