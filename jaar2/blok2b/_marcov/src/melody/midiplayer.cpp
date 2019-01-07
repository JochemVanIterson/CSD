#include "midiplayer.h"

// -------------------------------------------------------------------------- //
// ------------------------ Constructor & Destructor ------------------------ //
// -------------------------------------------------------------------------- //
MidiPlayer::MidiPlayer(std::string filename):MelodyProvider(){
  MidiProvider midiProvider(filename);
  notes = midiProvider.getNotes(0);
}
MidiPlayer::~MidiPlayer(){
}
