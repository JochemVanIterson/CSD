#include <iostream>
#include <string>

#include "instrument.hpp"
#include "subinstruments/inst_guitar.hpp"
#include "subinstruments/inst_piano.hpp"
#include "subinstruments/inst_strings.hpp"
#include "subinstruments/inst_winds.hpp"

int main() {
  InstWinds trompet1 = InstWinds("Trompet1");
  InstWinds trompet2 = InstWinds("Trompet2");
  InstWinds trompet3 = InstWinds("Trompet3");

  InstGuitar guitar1 = InstGuitar("Guitar1");
  InstGuitar guitar2 = InstGuitar("Guitar2");

  InstPiano piano1   = InstPiano("piano1");

  trompet1.makeSound(25);
  trompet2.makeSound(25);
  trompet3.makeSound(25);
  guitar1.makeSound(25);
  guitar2.makeSound(25);
  piano1.makeSound(25);
  return 0;
}
