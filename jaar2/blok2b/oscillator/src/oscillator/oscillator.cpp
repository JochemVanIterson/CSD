#include "oscillator.hpp"
#include "sine.hpp"

#include <iostream>
#include <string>

Oscillator::Oscillator(){}

Oscillator::Oscillator(double samplerate, double baseFrequency, double amplitude, std::string type){
  std::cout << "Oscillator::Oscillator() Constructor type: " << type << std::endl;
  this->baseFrequency = baseFrequency;
  this->amplitude = amplitude;
  generateHarmonics(type);
  for (int i=0; i<MAX_HAMRONICS; i++){
    harmonics[i] = new Sine(samplerate, baseFrequency*harmFreqs[i], harmAmps[i]);
    std::cout << "harmonics: " << harmFreqs[i]<< " : 1/"<< 1.0/harmAmps[i] << std::endl;
  }
}

Oscillator::~Oscillator(){
  std::cout << "Oscillator::Oscillator() Destructor" << std::endl;
  for (int i=0; i<MAX_HAMRONICS; i++){
    delete harmonics[i];
  }
  delete [] harmonics;
}

void Oscillator::setFrequency(double frequency){
  baseFrequency = frequency;
  for (int i=0; i<MAX_HAMRONICS; i++){
    harmonics[i]->setFrequency(baseFrequency*harmFreqs[i]);
  }
}
double Oscillator::getFrequency(){
  return baseFrequency;
}

double Oscillator::calc(){
  double value = 0;
  for (int i=0; i<MAX_HAMRONICS; i++){
    value += harmonics[i]->calc();
  }
  return value*amplitude;
}

void Oscillator::tick(){
  for (int i=0; i<MAX_HAMRONICS; i++){
    harmonics[i]->tick();
  }
}

void Oscillator::generateHarmonics(std::string type){
  std::cout << "Oscillator::generateHarmonics() type: " << type << std::endl;
  std::cout << "Max sines: " << MAX_HAMRONICS << std::endl;
  if(type=="sine"){
    harmFreqs[0] = 1.0;
    harmAmps[0] = 1.0;
  } else if(type=="saw"){
    for (int i=0; i<MAX_HAMRONICS; i++){
      harmFreqs[i] = (i+1);
      harmAmps[i] = 1.0/(i+1);
    }
  } else if(type=="square"){
    for (int i=0; i<MAX_HAMRONICS; i++){
      harmFreqs[i] = (i*2)+1;
      harmAmps[i] = 1.0/(i*2+1);
    }
  } else if(type=="triangle"){
    for (int i=0; i<MAX_HAMRONICS; i++){
      harmFreqs[i] = (i*2)+1;
      harmAmps[i] = 1.0/(harmFreqs[i]*harmFreqs[i]);
    }
  }
  for (int i=0; i<MAX_HAMRONICS; i++){

  }
}
