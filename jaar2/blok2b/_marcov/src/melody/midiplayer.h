#ifndef _MIDIPLAYER_H_
#define _MIDIPLAYER_H_

#include <iostream>
#include <string>

#include "melody_provider.h"
#include "../midi/midiProvider.h"

class MidiPlayer : public MelodyProvider{
public:
  MidiPlayer(std::string filename);
  ~MidiPlayer();

};

#endif
