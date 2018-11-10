#include <iostream>
#include <string>

#include "instrument.cpp"

int main() {
  std::cout << "main()" << std::endl; // stringout
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
  return 0;
}
