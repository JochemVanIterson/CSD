#ifndef _SINE_H
#define _SINE_H

#define PI_2 6.28318530717959

class Sine {
public:
  // Cons and Des
  Sine();
  Sine(double samplerate, double frequency, double amplitude);
  ~Sine();

  //Get and Set
  double getFrequency(){
    return frequency;
  }
  void setFrequency(double frequency){
    this->frequency = frequency;
  }

  // Functions
  double calc();
  void tick();

private:
  // Vars
  double phase = 0;
  double frequency = 0.0;
  double amplitude = 0.0;
  double samplerate;
};

#endif
