// ########################################################################## //
// ###############            Sub Instrument class            ############### //
// ###############                  Strings                   ############### //
// ############### Instrument specific functions for playback ############### //
// ########################################################################## //

#include <iostream>
#include <string>

#include "inst_strings.hpp"
#include "../instrument.hpp"

// --------------------- Constructor and Destructor --------------------- //
InstStrings::InstStrings(std::string name):Instrument(name, 20, 30){
  this->name = name;
  std::cout << "Object Strings created, name: " << name << std::endl;
  std::cout << "Ranging from " << rangeLow << " to " << rangeHigh << std::endl;
}
InstStrings::~InstStrings() {
  std::cout << "InstStrings::InstStrings destructor";
}

// --------------------- Functions -------------------------------------- //
bool InstStrings::makeSound(int note){
  std::cout << "Overwritten: ";
  if(rangeLow<=note && note<=rangeHigh){
    std::cout << "Make sound, name:" << name << " note:" << note << std::endl;
    return true;
  } else {
    std::cout << "Not in range, name:" << name << " note:" << note << std::endl;
    return false;
  }
  return false;
}
