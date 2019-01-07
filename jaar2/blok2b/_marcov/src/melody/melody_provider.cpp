#include "melody_provider.h"

// -------------------------------------------------------------------------- //
// ------------------------ Constructor & Destructor ------------------------ //
// -------------------------------------------------------------------------- //
MelodyProvider::MelodyProvider(){
  readIndex = 0;
}
MelodyProvider::~MelodyProvider(){
}

// -------------------------------------------------------------------------- //
// ------------------------------- Functions -------------------------------- //
// -------------------------------------------------------------------------- //
int MelodyProvider::getNote(){
  if(readIndex!=notes.size()){
    int value = notes[readIndex];
    readIndex++;
    return value;
  } else if(loop){
    readIndex = 0;
    return getNote();
  } else {
    return -1;
  }
}
void MelodyProvider::addNote(int note){
  notes.push_back(note);
}
void MelodyProvider::printList(){
  std::cout << "void Melody::printList():" << std::endl;

  std::cout << "\treadIndex: " << readIndex << "-> " << notes[readIndex] << std::endl;
  std::cout << "\twriteIndex: " << notes.size() << "-> " << notes[notes.size()-1] << std::endl;

  int walker = 0;
  while(walker<notes.size()) {
    std::cout << "\t" << walker << ": "<< notes[walker] << std::endl;
    walker++;
  }
}
void MelodyProvider::setLoop(bool loop){
  this->loop = loop;
}
