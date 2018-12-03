#include "generator.hpp"

#include <iostream>
#include <math.h>
#include <cmath>

Generator::Generator(){
  // std::cout << "Sine::Sine() Constructor" << std::endl;
}

Generator::~Generator(){
  // std::cout << "Sine::Sine() Destructor" << std::endl;
}

Generator::Generator(double samplerate, double frequency, double amplitude, std::string type){
  // std::cout << "Sine::Sine(double frequency, double amplitude); Constructor" << std::endl;
  this->samplerate = samplerate;
  this->frequency  = frequency;
  this->amplitude  = amplitude;
  this->type       = type;
}

double Generator::calc(){
  if(amplitude==0.0)return 0.0;
  double returnable = 0.;
  if(type=="sine"){
    returnable = (amplitude * sin(phase * PI_2 ));
  } else if(type=="saw"){
    returnable = (amplitude * ((1-std::fmod(phase, 1.0)) * 2 -1));
  } else if(type=="square"){
    if(std::fmod(phase, 1.0)<=.5){
      returnable = 1.0;
    } else {
      returnable = 0.0;
    }
    returnable *= amplitude;
  }
  return returnable;
}

void Generator::tick(){
  phase += frequency / samplerate;
}
