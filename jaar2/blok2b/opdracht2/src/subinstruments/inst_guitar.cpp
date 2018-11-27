// ########################################################################## //
// ###############            Sub Instrument class            ############### //
// ###############                  Guitar                   ############### //
// ############### Instrument specific functions for playback ############### //
// ########################################################################## //

#include <iostream>
#include <string>

#include "inst_guitar.hpp"
#include "../instrument.hpp"

// --------------------- Constructor and Destructor --------------------- //
InstGuitar::InstGuitar(std::string name):Instrument(name, 40, 64){
  this->name = name;
  std::cout << "Object Guitar created, name: " << name << std::endl;
  std::cout << "Ranging from " << rangeLow << " to " << rangeHigh << std::endl;
}
InstGuitar::~InstGuitar() {
  std::cout << "InstGuitar::InstGuitar destructor";
}
