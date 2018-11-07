import simpleaudio as sa
import time
import random
from random import randint


samples = [sa.WaveObject.from_wave_file("../../pythonExamples/audio/01_audioFiles/audioFiles/snare.wav"),
           sa.WaveObject.from_wave_file("../../pythonExamples/audio/01_audioFiles/audioFiles/kick.wav"),
           sa.WaveObject.from_wave_file("../../pythonExamples/audio/01_audioFiles/audioFiles/hat.wav")]

print ("what sample do you wanna play? you can choose from snare.wav or kick.wav or hihat.wav or combinations")
samplesToPlay = []

sound = input()
if (sound == "kick"):
	samplesToPlay.append(samples[1])
elif (sound == "snare"):
 	samplesToPlay.append(samples[0])
elif (sound == "hihat"):
 	samplesToPlay.append(samples[2])
elif (sound == "combinations"):
	samplesToPlay.extend(samples)
	random.shuffle(samplesToPlay)
else:
    print("wrong input")
    exit()

print ("good")
print ("what bpm do you wanna play with? please keep in mind you can only insert intergers as bpm values")
bpm = input()
bpm = int(bpm)
#calculate the duration of a quarternote
quarterNoteDuration = 60 / bpm
#calculate the duration of a sixteenthNote
sixteenthNote = quarterNoteDuration / 4.0

print ("what rhythm do you wanna play? you can choose from 5/4 or 7/8")
rhythm = input()


#def createSixthEight():

noteDurationsSixthEight = [ 1, 2, 4]
NoteSequence = []
timeSequence = []#NoteSequence * quarterNoteDuration
for Value in NoteSequence:
	timeSequence.append(Value*sixteenthNote)
#durationSixthEight =[]
timestamps = []
for timestamp in NoteSequence:
	previousValue = NoteSequence[-1]
	timestamps.append(timestamp+previousValue)

if rhythm == ("5/4"):
	while sum(NoteSequence) < 20:
		random.shuffle(noteDurationsSixthEight) # shuffle noteDurationsSixthEight
		newNote = noteDurationsSixthEight[0]   #voegt eertse element dus '1' toe en blijft doorgaan
		NoteSequence.append(newNote)
		print(NoteSequence)
		timestamps.append(newNote* quarterNoteDuration)
print (timestamps)
#print (durationSixthEight)

#timestamps = []
#for timestamp in NoteSequence:
	#previousValue = NoteSequence[-1]
	#timestamps.append(timestamp+previousValue)
#print(timestamps)

if rhythm == ("7/8"):
	while sum(NoteSequence) < 16:
		random.shuffle(noteDurationsSixthEight) # shuffle noteDurationsSixthEight
		newNote = noteDurationsSixthEight[0]   #voegt eertse element dus '1' toe en blijft doorgaan
		NoteSequence.append(newNote)
		print(NoteSequence)
		timestamps.append(newNote* quarterNoteDuration)
print (timestamps)




def playsequence (timestampssequence):
#play the sequence

	#retrive first timestamp
	timestamp = timestampssequence.pop(0)
	startTime = time.time()
	#print("startTime = " + str(startTime))
	keepPlaying = True
	while keepPlaying:
		currentTime = time.time()

		#print("currentTime - startTime = " + str(currentTime - startTime))
		#elapsedTime= currenttime - starttime
		if(currentTime - startTime >= timestamp):
			#playsample
			if len(samplesToPlay) > 0:
				randomValue = randint(0, len(samplesToPlay)-1)
			else:
				randomValue = 0
			print(randomValue)
			samplesToPlay[randomValue].play()
			startTime = time.time()
			print (timestamp)
			#if there are timestamps left in the timestamplist
			if timestampssequence:

					#retrive the next timestamp
					timestamp = timestampssequence.pop(0)
			else:
					# list is empty, stop loop
					keepPlaying = False
		else:
			#wait for a short moemnt
			time.sleep(0.001)

playsequence(timestamps)
