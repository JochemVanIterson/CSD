#include <iostream>
#include <string>

#include "Car.h"

// ------------------------------------- Car ------------------------------------- //
// ----------------- Constructors ----------------- //
Car::Car(std::string brnd, std::string clr){
  color = clr;
  brand = brnd;
}
Car::Car(std::string brnd, std::string clr, int spd, int drctn){
  color = clr;
  brand = brnd;
  speed = spd;
  direction = drctn;
}

// ----------------- Functions -------------------- //
void Car::setSpeed(int input){
  speed = input;
}
void Car::setDirection(int input){
  direction = input;
}
int Car::getSpeed(){
  return speed;
}
int Car::getDirection(){
  return direction;
}
std::string Car::getColor(){
  return color;
}
void Car::printOptions(){
  std::cout << "----------- Options -----------" << std::endl;
  std::cout << "Brand: " << brand << std::endl;
  std::cout << "Color: " << color << std::endl;
  std::cout << "Speed: " << speed << std::endl;
  std::cout << "Direc: " << direction << std::endl;
  std::cout << "Weel:  " << stWheel.getAngle() << std::endl;
}

// ------------------------------------- SteeringWheel ------------------------------------- //
// ----------------- Constructors ----------------- //
SteeringWheel::SteeringWheel(){
  angle = 10;
}

// ----------------- Functions -------------------- //
int SteeringWheel::getAngle(){
  return angle;
}
