#include <iostream>
#include <string>

#include "instrument.hpp"

int main() {
  Instrument inst1 = Instrument("test1");
  Instrument inst2 = Instrument("test2");

  std::cout << "\nStatic playback" << std::endl; // stringout
  inst1.makeSound();
  inst2.makeSound();
  inst1.makeSound();
  inst2.makeSound();

  std::cout << "\nRoll playback" << std::endl; // stringout
  inst1.roll(5);
  inst2.roll(2);
  inst2.roll(-1);
  return 0;
}
