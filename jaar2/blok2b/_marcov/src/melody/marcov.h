#ifndef _MARCOV_H_
#define _MARCOV_H_

#include <iostream>
#include <map>
#include <iomanip>
#include <string>

#include "melody.h"

#include "../midi/MidiFile.h"
#include "../midi/Options.h"

class Marcov : public Melody{
public:
  Marcov(int marcovSize);
  ~Marcov();

  int getNote();
  void learnMarcov(std::string filename);
  void printAlgorithm();
private:
  int marcovSize;
  std::map<std::string, std::map<std::string, int>> marcov_alg;
  std::vector<int> note_history;
  std::string array2string(std::vector<int> &writableArray, std::string delimiter);
  void array_insert_end(std::vector<int> &array, int maxsize, int value);
};

#endif
