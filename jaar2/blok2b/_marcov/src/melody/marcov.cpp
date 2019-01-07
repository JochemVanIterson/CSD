#include "marcov.h"

// -------------------------------------------------------------------------- //
// ------------------------ Constructor & Destructor ------------------------ //
// -------------------------------------------------------------------------- //
Marcov::Marcov(int marcovSize):MelodyProvider(){
  this->marcovSize = marcovSize;
}
Marcov::~Marcov(){
}

// -------------------------------------------------------------------------- //
// ------------------------------- Overwrites ------------------------------- //
// -------------------------------------------------------------------------- //
void Marcov::addNote(){
  int value = getSuccessor();
  MelodyProvider::addNote(value);
}
int Marcov::getNote(){
  addNote();
  return MelodyProvider::getNote();
}

// -------------------------------------------------------------------------- //
// ------------------------------- Functions -------------------------------- //
// -------------------------------------------------------------------------- //

// -------- Public -------- //
void Marcov::learnMarcov(std::string filename){
  MidiProvider midiProvider(filename);
  std::vector<int> notes = midiProvider.getNotes(0);
  // Tools::printVectorInt("notes", notes);

  std::vector<int> marcov_hist(marcovSize);
  std::string marcov_hist_str = "leeg";

  // --------------- Generate Marcov algorithm --------------- //
  // Ignores the first few notes (marcovSize), and adds those at the end
  for(int walker = 0; walker<(notes.size()+marcovSize); walker++){
    int walkerMod = walker % notes.size();
    int note = notes[walkerMod];
    marcov_hist_str = Tools::array2string(marcov_hist, ',');
    if(marcov_hist.size()!=0 && marcov_hist[0]!=0){
      marcov_alg[marcov_hist_str][std::to_string(note)]++;
    }
    Tools::array_insert_end(marcov_hist, marcovSize, note);
  }

  printAlgorithm();
}
void Marcov::initMelody(){
  // ----------- Chooses random itm from the list ----------- //
  auto it = marcov_alg.begin();
  int random_int = Tools::rand_between(0, marcov_alg.size());
  std::advance(it, random_int);
  std::string random_key = it->first;

  std::vector<int> note_history = Tools::string2array(random_key, ',');

  for(int itm : note_history){
    MelodyProvider::addNote(itm);
  }
}
void Marcov::printAlgorithm(){
  if(marcov_alg.size()==0){
    std::cout << "No algorithm set" << std::endl;
    return;
  }
  std::cout << "Map log:" << std::endl;
  std::map<std::string, int>::iterator itr1;
  std::map<std::string, std::map<std::string, int> >::iterator itr2;
  for(itr2 = marcov_alg.begin(); itr2 != marcov_alg.end(); itr2++){
    std::map<std::string, int> data = itr2->second;
    std::cout << itr2->first << std::endl;
    for(itr1 = data.begin(); itr1 != data.end(); itr1++){
      std::cout << "  " << itr1->first << ": " << itr1->second << std::endl;
    }
  }
}

int Marcov::getSuccessor(){
  // takes the last <marcovSize> items from the note list, and calculates the successing note.

  std::vector<int> note_history;
  for(int walker = notes.size()-marcovSize; walker < notes.size(); walker++){
    note_history.push_back(notes[walker]);
  }
  std::string note_history_str = Tools::array2string(note_history, ',');
  std::map<std::string, int> MarcovOptions = marcov_alg[note_history_str];

  std::vector<int> MarcovOptionsArray;
  for(auto itm : MarcovOptions){
    for(int walker = 0; walker<itm.second; walker++){
      MarcovOptionsArray.push_back(std::stoi(itm.first));
    }
  }

  int random_int = Tools::rand_between(0, MarcovOptionsArray.size());
  int random_note = MarcovOptionsArray[random_int];

  return random_note;
}
