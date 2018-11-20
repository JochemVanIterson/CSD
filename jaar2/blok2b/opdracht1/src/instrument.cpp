#include <iostream>
#include <string>

#include "instrument.hpp"

Instrument::Instrument(std::string soundid) {
  sound = soundid;
  std::cout << "Object created, name: " << sound << std::endl;
}
bool Instrument::makeSound(){
  std::cout << "Make sound, name: " << sound << std::endl;
  return true;
}
bool Instrument::roll(int amount){
  if(amount<=0){
    std::cout << "\nNegative amount" << std::endl;
    return false;
  }
  for ( int walker = 0; walker<amount; walker++ ) {
    makeSound();
  }
  return true;
}
