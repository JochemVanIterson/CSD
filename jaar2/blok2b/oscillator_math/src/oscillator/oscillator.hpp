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

  void setAmplitude(double amplitude);
  double getAmplitude();

  void setType(std::string type);
  void setDebug(bool debug);

  // Funcs
  double calc();
  void tick();
private:
  // Vars
  double samplerate;
  double baseFrequency;
  double amplitude;
  std::string type;
  bool   debug;

  double harmFreqs[MAX_HAMRONICS] = {0.0};
  double harmAmps[MAX_HAMRONICS] = {0.0};
  Generator** harmonics = new Generator*[MAX_HAMRONICS];

  void generateHarmonics(std::string type);
  void setHarmonics(std::string type);
};

#endif
