#include "voice.h"
Voice::Voice(){
  
}
Voice::Voice(double samplerate, std::string type){
  this->samplerate = samplerate;
  this->type = type;
  setType(type);
}

Voice::~Voice(){
  delete oscillator;
  oscillator = nullptr;
}

void Voice::setType(std::string type){
  if(type=="sine")oscillator = new Sine(samplerate, frequency);
  else if(type=="saw")oscillator = new Saw(samplerate, frequency);
  else if(type=="square")oscillator = new Square(samplerate, frequency);
  else if(type=="triangle")oscillator = new Triangle(samplerate, frequency);
  else {
    oscillator = new Sine(samplerate, frequency);
    std::cout << "Unknown type" << std::endl;
  }
}

void Voice::noteOn(int midiNote, double amplitude){
  this->frequency = m2f(midiNote);
  oscillator->setFrequency(this->frequency);
  this->amplitude = amplitude;
  this->isPlaying = true;
}
void Voice::noteOff(){
  this->isPlaying = false;
}

double Voice::getSample(){
  return oscillator->getSample();
}
void Voice::tick(){
  oscillator->tick();
}

double Voice::m2f(int midiNote){
  // 2^((m−69)/12)
  double value = std::pow(2.0, (midiNote-69)/12.)*440.;
  return value;
}
