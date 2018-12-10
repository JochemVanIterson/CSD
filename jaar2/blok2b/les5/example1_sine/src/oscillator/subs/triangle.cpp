#include "triangle.h"


// Constructor and destructor
Triangle::Triangle(double samplerate, double frequency) :
  Oscillator(samplerate, frequency)
{
  // TODO - use setFrequency and phase instead, to prevent outrange values
  std::cout << "\nInside Triangle::oscillator (double frequency, double phase)"
    << "\nfrequency: " << frequency
    << "\nphase: " << phase;
}

Triangle::~Triangle()
{
  std::cout << "\nInside Triangle::~Saw";
}


void Triangle::calculate()
{
  // calculate sample
  // NOTE: sin() method is not the most efficient way to calculate the sine value
  if(phase<.5){
    sample = phase;
  } else {
    sample = 1. - phase;
  }
  sample = sample*2-1;
}
