#ifndef _OSCILLATOR_H
#define _OSCILLATOR_H

#define MAX_HAMRONICS 64

#include <string>

#include "generator.hpp"

class Oscillator {
public:
  // Cons and Des
  Oscillator();
  Oscillator(double samplerate, double frequency, double amplitude, std::string type, bool debug);
  ~Oscillator();

  // Get and Set
  void setFrequency(double frequency);
  double getFrequency();

  // Funcs
  double calc();
  void tick();
private:
  // Vars
  bool   debug;
  double amplitude;
  double baseFrequency;
  double harmFreqs[MAX_HAMRONICS] = {0.0};
  double harmAmps[MAX_HAMRONICS] = {0.0};
  Generator** harmonics = new Generator*[MAX_HAMRONICS];

  void generateHarmonics(std::string type);
};

#endif
