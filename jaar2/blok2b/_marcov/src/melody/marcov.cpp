#include "marcov.h"

#define MARCOVSIZE 3

// -------------------------------------------------------------------------- //
// ------------------------ Constructor & Destructor ------------------------ //
// -------------------------------------------------------------------------- //
Marcov::Marcov():Melody(){
  std::cout << "Marcov::Marcov()" << std::endl;
}
Marcov::~Marcov(){
  std::cout << "Marcov::~Marcov()" << std::endl;
}

// -------------------------------------------------------------------------- //
// ------------------------------- Overwrites ------------------------------- //
// -------------------------------------------------------------------------- //
int Marcov::getNote(){
  std::cout << "int Marcov::getNote()" << std::endl;
  return Melody::getNote();
}

// -------------------------------------------------------------------------- //
// ------------------------------- Functions -------------------------------- //
// -------------------------------------------------------------------------- //
void Marcov::learnMarcov(std::string filename){
  smf::MidiFile midifile;
  midifile.read(filename);
  midifile.doTimeAnalysis();
  midifile.linkNotePairs();

  int tracks = midifile.getTrackCount();
  for (int track=0; track<tracks; track++) {
    int marcov_hist[MARCOVSIZE] = {};
    std::string marcov_hist_str = "leeg";

    // --------------- Convert from midi events to note list --------------- //
    std::vector<int> notes;
    for (int event=0; event<midifile[track].size(); event++) {
      if(!midifile[track][event].isNoteOn()) continue;
      notes.push_back(midifile[track][event].getP1());
    }

    // --------------- Generate Marcov algorithm --------------- //
    // Ignores the first few notes (MARCOVSIZE), and adds those at the end
    for(int walker = 0; walker<(notes.size()+MARCOVSIZE); walker++){
      int walkerMod = walker % notes.size();
      int note = notes[walkerMod];
      marcov_hist_str = array2string(marcov_hist, MARCOVSIZE, ",");
      if(marcov_hist[0]!=0){
        marcov_alg[marcov_hist_str][std::to_string(note)]++;
        std::cout << walkerMod << " -> " << "inserted: " << marcov_hist_str << " Note:" << note << std::endl;
      }
      array_insert_end(marcov_hist, MARCOVSIZE, note);
    }
  }
  printAlgorithm();
}
std::string Marcov::array2string(int writableArray[], int size, std::string delimiter){
  std::string stringValue = "";
  for(int walker = 0; walker<size; walker++){
    if(stringValue != "")stringValue.append(delimiter);
    stringValue.append(std::to_string(writableArray[walker]));
  }
  return stringValue;
}
void Marcov::array_insert_end(int array[], int size, int value){
  for(int walker = 1; walker<size; walker++){
    array[walker-1] = array[walker];
  }
  array[size-1] = value;
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
