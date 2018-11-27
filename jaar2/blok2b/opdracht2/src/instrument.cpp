// ########################################################################## //
// ###############              Instrument class              ############### //
// ############### basic functions for playing an instrument  ############### //
// ########################################################################## //

#include <iostream>
#include <string>

#include "instrument.hpp"
// --------------------- Constructor and Destructor --------------------- //
Instrument::Instrument(std::string name, int rngLow, int rngHigh) {
  this->name = name;
  this->rangeLow = rngLow;
  this->rangeHigh = rngHigh;
  std::cout << "Instrument::Instrument constructor(" << name << ", " << rngLow << ", " << rngHigh <<")" << std::endl;
}
Instrument::~Instrument() {
  std::cout << "Instrument::Instrument destructor (" << name << ", " << rangeLow << ", " << rangeHigh <<")" << std::endl;
}

// --------------------- Functions -------------------------------------- //
bool Instrument::makeSound(int note){
  if(rangeLow<=note && note<=rangeHigh){
    std::cout << "Make sound, name:" << name << " note:" << note << std::endl;
    return true;
  } else {
    std::cout << "Not in range, name:" << name << " note:" << note << std::endl;
    return false;
  }
  return false;
}
bool Instrument::roll(int note, int amount){
  for ( int walker = 0; walker<amount; walker++ ) {
    makeSound(note);
  }
  return true;
}
