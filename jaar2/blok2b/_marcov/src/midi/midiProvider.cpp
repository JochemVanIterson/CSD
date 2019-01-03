#include "midiProvider.h"

MidiProvider::MidiProvider(std::string midiFileName){
  midifile.read(midiFileName);
  midifile.doTimeAnalysis();
  midifile.linkNotePairs();

  tracks = midifile.getTrackCount();
}
MidiProvider::~MidiProvider(){

}

std::vector<int> MidiProvider::getNotes(int track){
  std::vector<int> notes;
  for (int event=0; event<midifile[track].size(); event++) {
    if(!midifile[track][event].isNoteOn()) continue;
    notes.push_back(midifile[track][event].getP1());
  }
  return notes;
}
