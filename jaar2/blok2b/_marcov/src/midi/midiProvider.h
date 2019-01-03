#ifndef _MIDIPROVIDER_H
#define _MIDIPROVIDER_H

#include "MidiFile.h"

#include <string>
#include <iostream>

class MidiProvider{
public:
  MidiProvider(std::string midiFileName);
  ~MidiProvider();

  std::vector<int> getNotes(int track);
private:
  smf::MidiFile midifile;
  int tracks = -1;
};

#endif
