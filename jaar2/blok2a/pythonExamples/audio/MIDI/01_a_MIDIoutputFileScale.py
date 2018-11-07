from midiutil.MidiFile import MIDIFile
from midiutil import MIDIFile

"""
Documentation about midiutil:
http://midiutil.readthedocs.io/en/stable/

This script contains an example from https://pypi.python.org/pypi/MIDIUtil/.
It generates a midi file with a major scale.

HANDS-ON TIPS
- Alter the code:
  Can you predict the resulting changes when you alter the following variables:
  [track, channel, time, duration, tempo, volume]?
- Alter the code:
  What happens if the file "major-scale.mid" already exists?
  Implement: Before writing the output MIDIfile, check if a file with the same
  name already exists and if so ask the user if he / she wants to overwrite the
  existing file or to rename the output file.
"""


degrees  = [60, 62, 64, 65, 67, 69, 71, 72]  # MIDI note number
track    = 0
channel  = 0
time     = 0    # In beats
duration = 1    # In beats
tempo    = 60   # In BPM
volume   = 100  # 0-127, as per the MIDI standard

MyMIDI = MIDIFile(1)  # One track, defaults to format 1 (tempo track is created
                      # automatically)
MyMIDI.addTempo(track, time, tempo)

for i, pitch in enumerate(degrees):
    MyMIDI.addNote(track, channel, pitch, time + i, duration, volume)

with open("major-scale.mid", "wb") as output_file:
    MyMIDI.writeFile(output_file)
