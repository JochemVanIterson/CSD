#include "sine.hpp"

#include <iostream>
#include <math.h>

Sine::Sine(){
  // std::cout << "Sine::Sine() Constructor" << std::endl;
}

Sine::~Sine(){
  // std::cout << "Sine::Sine() Destructor" << std::endl;
}

Sine::Sine(double samplerate, double frequency, double amplitude){
  // std::cout << "Sine::Sine(double frequency, double amplitude); Constructor" << std::endl;
  this->samplerate = samplerate;
  this->frequency  = frequency;
  this->amplitude  = amplitude;
}

double Sine::calc(){
  if(amplitude==0.0)return 0.0;
  double returnable = (amplitude * sin(phase * PI_2 ));
  return returnable;
}

void Sine::tick(){
  phase += frequency / samplerate;
}
