#include <iostream>
#include <string>

#include "Car.h"

int main() {
  Car mooieAuto("Volvo", "groen", 1, 0);
  std::cout << "Color: " << mooieAuto.getColor() << std::endl;
  std::cout << "Speed: " << mooieAuto.getSpeed() << std::endl;
  std::cout << "Direc: " << mooieAuto.getDirection() << std::endl;
  std::cout << "Weel:  " << mooieAuto.stWheel.getAngle() << std::endl;

  std::cout << std::endl;
  mooieAuto.setSpeed(50);
  mooieAuto.setDirection(90);
  std::cout << "Speed: " << mooieAuto.getSpeed() << std::endl;
  std::cout << "Direc: " << mooieAuto.getDirection() << std::endl;

  mooieAuto.printOptions();

  std::cout << "\n############################## Lelijke auto ##############################" << std::endl;
  Car lelijkeAuto("Peugot", "paars");
  lelijkeAuto.printOptions();
  return 0;
}
