#include <iostream>
#include <string>

#include "dbgPrint/dbgPrint.cpp"
#include "instrument.cpp"

int main() {
  Instrument inst1 = Instrument("test1");
  Instrument inst2 = Instrument("test2");

  dbgPrint::d("", "Static playback");
  // std::cout << "\nStatic playback" << std::endl; // stringout
  inst1.makeSound();
  inst2.makeSound();
  inst1.makeSound();
  inst2.makeSound();

  dbgPrint::d("", "Roll playback");
  // std::cout << "\nRoll playback" << std::endl; // stringout
  inst1.roll(5);
  inst2.roll(2);
  return 0;
}
