// ########################################################################## //
// ###############            Sub Instrument class            ############### //
// ###############                  Winds                   ############### //
// ############### Instrument specific functions for playback ############### //
// ########################################################################## //

#include <iostream>
#include <string>

#include "inst_winds.hpp"
#include "../instrument.hpp"

// --------------------- Constructor and Destructor --------------------- //
InstWinds::InstWinds(std::string name):Instrument(name, 20, 30){
  this->name = name;
  std::cout << "Object Winds created, name: " << name << std::endl;
  std::cout << "Ranging from " << rangeLow << " to " << rangeHigh << std::endl;
}
InstWinds::~InstWinds() {
  std::cout << "InstWinds::InstWinds destructor";
}
