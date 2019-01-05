#include "midiplayer.h"

// -------------------------------------------------------------------------- //
// ------------------------ Constructor & Destructor ------------------------ //
// -------------------------------------------------------------------------- //
MidiPlayer::MidiPlayer(std::string filename):MelodyProvider(){
  std::cout << "MidiPlayer::MidiPlayer()" << std::endl;
  MidiProvider midiProvider(filename);
  notes = midiProvider.getNotes(0);
}
MidiPlayer::~MidiPlayer(){
  std::cout << "MidiPlayer::~MidiPlayer()" << std::endl;
}
