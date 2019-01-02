#include "melody.h"

// -------------------------------------------------------------------------- //
// ------------------------ Constructor & Destructor ------------------------ //
// -------------------------------------------------------------------------- //
Melody::Melody(){
  std::cout << "Melody::Melody()" << std::endl;
  readIndex = 0;
  writeIndex = 0;
}
Melody::~Melody(){
  std::cout << "Melody::~Melody()" << std::endl;
}

// -------------------------------------------------------------------------- //
// ------------------------------- Functions -------------------------------- //
// -------------------------------------------------------------------------- //
int Melody::getNote(){
  if(readIndex!=(writeIndex)){
    int value = notes[readIndex];
    readIndex = (readIndex+1) % NUM_NOTES;
    return value;
  } else {
    return -1;
  }
}
void Melody::addNote(int note){
  std::cout << readIndex << ":" << writeIndex << std::endl;
  if(note<=0){
    std::cout << "Negative note " << note << std::endl;
    return;
  }
  if(writeIndex!=(readIndex-1)){
    notes[writeIndex] = note;
    writeIndex = (writeIndex+1) % NUM_NOTES;
  } else {
    std::cout << "void Melody::addNote(int note): Couldn't add note " << note << std::endl;
  }
}
void Melody::printList(){
  std::cout << "void Melody::printList():" << std::endl;

  std::cout << "\treadIndex: " << readIndex << "-> " << notes[readIndex] << std::endl;
  std::cout << "\twriteIndex: " << writeIndex << "-> " << notes[writeIndex] << std::endl;

  int walker = 0;
  while(walker<NUM_NOTES) {
    std::cout << "\t" << walker << ": "<< notes[walker] << std::endl;
    walker++;
  }
}
