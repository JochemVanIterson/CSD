# simpleaudio is imported as sa -> shorter name
import simpleaudio as sa

"""
An example project in which three wav files are played after eachother.

------ HANDS-ON TIPS ------
- Answer the following question before running the code:
  Do you expect to hear the samples played simultaniously or after eachother?
  Why?
  # No, sampleHighPlay.wait_done()

- Alter the code:
  Play the sounds simultaniously.
  # remove sampleLowPlay.wait_done()

- Alter the code:
  Ask the user to choice which one of the three samples should be played and
  only play the chosen sample.
  # Done
"""

files = ["../audioFiles/Pop.wav", "../audioFiles/Laser1.wav", "../audioFiles/Dog2.wav"]
for index, entry in enumerate(files):
    print("("+str(index)+")", entry)

chosenIndex = int(input("Which file? "))
chosenFile = files[chosenIndex]

# load 3 audioFiles
sample = sa.WaveObject.from_wave_file(chosenFile)

# play high sample
samplePlay = sample.play()
samplePlay.wait_done()
