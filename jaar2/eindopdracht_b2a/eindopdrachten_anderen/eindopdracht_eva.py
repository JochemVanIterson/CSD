import time
import simpleaudio as sa
import random
import midiutil
from midiutil.MidiFile import MIDIFile
import os.path
import threading
from threading import Thread

#inladen samples
wave_obj_snare = sa.WaveObject.from_wave_file("../../pythonExamples/audio/01_audioFiles/audioFiles/snare.wav")
wave_obj_kick = sa.WaveObject.from_wave_file("../../pythonExamples/audio/01_audioFiles/audioFiles/kick.wav")
wave_obj_hihat = sa.WaveObject.from_wave_file("../../pythonExamples/audio/01_audioFiles/audioFiles/hat.wav")

#mogelijke lengtes
noteLength_choice = [0.5, 1.0, 1.5, 2.0]

#-----------functions-----------#

def playSnare():
    play_obj = wave_obj_snare.play()

def playKick():
    play_obj = wave_obj_kick.play()

def playHihat():
    play_obj = wave_obj_hihat.play()

#---------------------5/4---------------------#
global noteLengths1_VV, noteLengths2_VV, noteLengths3_VV
global currentNote1_VV, currentNote2_VV, currentNote3_VV

noteLengths1_VV = []
noteLengths2_VV = []
noteLengths3_VV = []
currentNote1_VV = 0.
currentNote2_VV = 0.
currentNote3_VV = 0.

#ritmes voor laag 1 waarbij de lengte 5 tellen is
def laag1_VV():
    randomNote1 = random.choice(noteLength_choice)
    noteLengths1_VV.append(randomNote1)
    if sum(noteLengths1_VV) == 5:
        print(noteLengths1_VV)
        for length in noteLengths1_VV:
            time.sleep(length * (60 / BPM))
            playKick()
        return 0
    else:
        if sum(noteLengths1_VV) >= 5:
           noteLengths1_VV.clear()
           return laag1_VV()
        else:
            return laag1_VV()

#ritmes voor laag 2 waarbij de lengte 5 tellen is
def laag2_VV():
    randomNote2 = random.choice(noteLength_choice)
    noteLengths2_VV.append(randomNote2)
    if sum(noteLengths2_VV) == 5:
        print(noteLengths2_VV)
        for length in noteLengths2_VV:
            time.sleep(length * (60 / BPM))
            playSnare()
        return 0
    else:
        if sum(noteLengths2_VV) >= 5:
           noteLengths2_VV.clear()
           return laag2_VV()
        else:
            return laag2_VV()

#ritmes voor laag 3 waarbij de lengte 5 tellen is
def laag3_VV():
    randomNote3 = random.choice(noteLength_choice)
    noteLengths3_VV.append(randomNote3)
    if sum(noteLengths3_VV) == 5:
        print(noteLengths3_VV)
        for length in noteLengths3_VV:
            time.sleep(length * (60 / BPM))
            playHihat()
        return 0
    else:
        if sum(noteLengths3_VV) >= 5:
           noteLengths3_VV.clear()
           return laag3_VV()
        else:
            return laag3_VV()
#----------------------------------------------#
#---------------------7/8---------------------#
global noteLengths1_ZA, noteLengths2_ZA, noteLengths3_ZA
global currentNote1_ZA, currentNote2_ZA, currentNote3_ZA

noteLengths1_ZA = []
noteLengths2_ZA = []
noteLengths3_ZA = []
currentNote1_ZA = 0.
currentNote2_ZA = 0.
currentNote3_ZA = 0.

#ritmes voor laag 1 waarbij de lengte 7 tellen is
def laag1_ZA():
    randomNote1 = random.choice(noteLength_choice)
    noteLengths1_ZA.append(randomNote1)
    if sum(noteLengths1_ZA) == 7:
        print(noteLengths1_ZA)
        for length in noteLengths1_ZA:
            time.sleep(length * ((60 / BPM) / 2))
            playKick()
        return 0
    else:
        if sum(noteLengths1_ZA) >= 7:
           noteLengths1_ZA.clear()
           return laag1_ZA()
        else:
            return laag1_ZA()

#ritmes voor laag 2 waarbij de lengte 7 tellen is
def laag2_ZA():
    randomNote2 = random.choice(noteLength_choice)
    noteLengths2_ZA.append(randomNote2)
    if sum(noteLengths2_ZA) == 7:
        print(noteLengths2_ZA)
        for length in noteLengths2_ZA:
            time.sleep(length * ((60 / BPM) / 2))
            playSnare()
        return 0
    else:
        if sum(noteLengths2_ZA) >= 7:
           noteLengths2_ZA.clear()
           return laag2_ZA()
        else:
            return laag2_ZA()

#ritmes voor laag 3 waarbij de lengte 7 tellen is
def laag3_ZA():
    randomNote3 = random.choice(noteLength_choice)
    noteLengths3_ZA.append(randomNote3)
    if sum(noteLengths3_ZA) == 7:
        print(noteLengths3_ZA)
        for length in noteLengths3_ZA:
            time.sleep(length * ((60 / BPM) / 2))
            playHihat()
        return 0
    else:
        if sum(noteLengths3_ZA) >= 7:
           noteLengths3_ZA.clear()
           return laag3_ZA()
        else:
            return laag3_ZA()

#----------------------------------------------#

mf = MIDIFile(3)    #3 tracks

def MIDI_VV(mf, noteLengths1_VV, noteLengths2_VV, noteLengths3_VV, currentNote1_VV, currentNote2_VV, currentNote3_VV):
    if mf is None:
        mf = MIDIFile(3)    #3 tracks
        startTime = 0       #begint bij het begin
        track = 0
        mf.addTrackName(track, startTime, "5/4 Beat")
        mf.addTempo(track, startTime, BPM)
        return MIDI_VV(mf, noteLengths1_VV, noteLengths2_VV, noteLengths3_VV, currentNote1_VV, currentNote2_VV, currentNote3_VV)

    if len(noteLengths1_VV) == 0:
        print("...")
    else:
        track = 0                           #eerste track
        channel = 10                        #percussie
        volume = 100
        instrument = 35                     #kick
        time = currentNote1_VV              #startpunt noot
        duration = noteLengths1_VV.pop(0)   #1e nootlengte uit de lijst
        mf.addNote(track, channel, instrument, time, duration, volume) #voeg noot toe aan midifile
        currentNote1_VV += duration
        return MIDI_VV(mf, noteLengths1_VV, noteLengths2_VV, noteLengths3_VV, currentNote1_VV, currentNote2_VV, currentNote3_VV)

    if len(noteLengths2_VV) == 0:
        print("...")
    else:
        track = 0                           #tweede track (voor losse tracks gebruik 1)
        startTime = 0
        channel = 10                        #percussie
        volume = 100
        instrument = 38                     #snare
        time = currentNote2_VV              #startpunt noot
        duration = noteLengths2_VV.pop(0)   #1e nootlengte uit de lijst
        mf.addNote(track, channel, instrument, time, duration, volume)
        currentNote2_VV += duration
        return MIDI_VV(mf, noteLengths1_VV, noteLengths2_VV, noteLengths3_VV, currentNote1_VV, currentNote2_VV, currentNote3_VV)

    if len(noteLengths3_VV) == 0:
        print("Done")

        output_file = input("Name MIDI-file: ")
        #write to disk
        with open("output.mid", 'wb') as output_file:
            mf.writeFile(output_file)
    else:
        track = 0                           #derde track (voor losse tracks gebruk 2)
        startTime = 0
        channel = 10                        #percussie
        volume = 100
        instrument = 42                     #hihat
        time = currentNote3_VV              #startpunt noot
        duration = noteLengths3_VV.pop(0)   #1e nootlengte uit de lijst
        mf.addNote(track, channel, instrument, time, duration, volume)
        currentNote3_VV += duration
        return MIDI_VV(mf, noteLengths1_VV, noteLengths2_VV, noteLengths3_VV, currentNote1_VV, currentNote2_VV, currentNote3_VV)

def MIDI_ZA(mf, noteLengths1_ZA, noteLengths2_ZA, noteLengths3_ZA, currentNote1_ZA, currentNote2_ZA, currentNote3_ZA):
    if mf is None:
        mf = MIDIFile(3)    #3 tracks
        startTime = 0       #begint bij het begin
        track = 0
        mf.addTrackName(track, startTime, "7/8 Beat")
        mf.addTempo(track, startTime, BPM)
        return MIDI_ZA(mf, noteLengths1_ZA, noteLengths2_ZA, noteLengths3_ZA, currentNote1_ZA, currentNote2_ZA, currentNote3_ZA)

    if len(noteLengths1_ZA) == 0:
        print("...")
    else:
        track = 0                           #eerste track
        channel = 10                        #percussie
        volume = 100
        instrument = 35                     #kick
        time = currentNote1_ZA              #startpunt noot
        duration = noteLengths1_ZA.pop(0)   #1e nootlengte uit de lijst
        mf.addNote(track, channel, instrument, time, duration, volume) #voeg noot toe aan midifile
        currentNote1_ZA += duration
        return MIDI_ZA(mf, noteLengths1_ZA, noteLengths2_ZA, noteLengths3_ZA, currentNote1_ZA, currentNote2_ZA, currentNote3_ZA)

    if len(noteLengths2_ZA) == 0:
        print("...")
    else:
        track = 0                           #tweede track (voor losse tracks gebruik 1)
        startTime = 0
        channel = 10                        #percussie
        volume = 100
        instrument = 38                     #snare
        time = currentNote2_ZA              #startpunt noot
        duration = noteLengths2_ZA.pop(0)   #1e nootlengte uit de lijst
        mf.addNote(track, channel, instrument, time, duration, volume)
        currentNote2_ZA += duration
        return MIDI_ZA(mf, noteLengths1_ZA, noteLengths2_ZA, noteLengths3_ZA, currentNote1_ZA, currentNote2_ZA, currentNote3_ZA)

    if len(noteLengths3_ZA) == 0:
        print("Done")
        #write to disk
        with open("output.mid", 'wb') as output_file:
            mf.writeFile(output_file)
    else:
        track = 0                           #derde track (voor losse tracks gebruk 2)
        startTime = 0
        channel = 10                        #percussie
        volume = 100
        instrument = 42                     #hihat
        time = currentNote3_ZA              #startpunt noot
        duration = noteLengths3_ZA.pop(0)   #1e nootlengte uit de lijst
        mf.addNote(track, channel, instrument, time, duration, volume)
        currentNote3_ZA += duration
        return MIDI_ZA(mf, noteLengths1_ZA, noteLengths2_ZA, noteLengths3_ZA, currentNote1_ZA, currentNote2_ZA, currentNote3_ZA)

def quit():
    stop = input("Quit? (yes/no) ")
    if stop == 'yes':
        quit
    else:
        return playBeat()

def save_VV():
    save = input("Save as MIDI file? (yes/no) ")
    if save == 'yes':
        MIDI_VV(None, noteLengths1_VV, noteLengths2_VV, noteLengths3_VV, currentNote1_VV, currentNote2_VV, currentNote3_VV)
    else:
        quit()

def save_ZA():
    save = input("Save as MIDI file? (yes/no) ")
    if save == 'yes':
        MIDI_ZA(None, noteLengths1_ZA, noteLengths2_ZA, noteLengths3_ZA, currentNote1_ZA, currentNote2_ZA, currentNote3_ZA)
    else:
        quit()

def playBeat():
    if maatsoort == 5/4:
        print('5/4 playing')
        l1_VV = Thread(target = laag1_VV)
        l2_VV = Thread(target = laag2_VV)
        l3_VV = Thread(target = laag3_VV)

        l1_VV.start()
        l2_VV.start()
        l3_VV.start()
        save_VV()
    else:
        print('7/8')
        l1_ZA = Thread(target = laag1_ZA)
        l2_ZA = Thread(target = laag2_ZA)
        l3_ZA = Thread(target = laag3_ZA)

        l1_ZA.start()
        l2_ZA.start()
        l3_ZA.start()
        save_ZA()

#-----------input-----------#
BPM = int(input("BPM: "))
maatsoort = eval(input("Time signature (5/4 or 7/8): "))

playBeat()
