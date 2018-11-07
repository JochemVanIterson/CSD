#import the simpleaudio module
import simpleaudio as sa

#create a waveObject from a sound file
waveObject = sa.WaveObject.from_wave_file("./audioFiles/aSound.wav")

#define a function to play the sound multiple times
def play (numTimes):
	for i in range(numTimes):
		print(i + 1, ". Playing sound!")
		playObject = waveObject.play()
		playObject.wait_done()

#Ask the user how many times we should play the sound
inputPlayNumTimes = input("Please enter the number of times " +
  "you want to play THE SOUND: ")

#play the sound 'inputPlayNumTimes' times
play(int(inputPlayNumTimes))
