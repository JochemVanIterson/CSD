#ifndef _MARCOV_H_
#define _MARCOV_H_

#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <random>
#include <sstream>
#include "../tools/tools.h"

#include "melody_provider.h"

#include "../midi/midiProvider.h"

class Marcov : public MelodyProvider{
public:
  Marcov(int marcovSize);
  ~Marcov();

  void addNote();
  int getNote();

  void learnMarcov(std::string filename);
  void initMelody();
  void printAlgorithm();
private:
  int marcovSize;
  std::map<std::string, std::map<std::string, int>> marcov_alg;
  int getSuccessor();
};

#endif
