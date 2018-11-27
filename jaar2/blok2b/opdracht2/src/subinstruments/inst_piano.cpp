// ########################################################################## //
// ###############            Sub Instrument class            ############### //
// ###############                  Piano                   ############### //
// ############### Instrument specific functions for playback ############### //
// ########################################################################## //

#include <iostream>
#include <string>

#include "inst_piano.hpp"
#include "../instrument.hpp"

// --------------------- Constructor and Destructor --------------------- //
InstPiano::InstPiano(std::string name):Instrument(name, 0, 85){
  this->name = name;
  std::cout << "Object Piano created, name: " << name << std::endl;
  std::cout << "Ranging from " << rangeLow << " to " << rangeHigh << std::endl;
}
InstPiano::~InstPiano() {
  std::cout << "InstPiano::InstPiano destructor";
}
