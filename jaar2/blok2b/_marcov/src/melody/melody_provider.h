#ifndef _MELODY_H
#define _MELODY_H

#include <iostream>
#include <vector>

class MelodyProvider{
public:
  // constructor and destructor
  MelodyProvider();
  ~MelodyProvider();

  // returns the note at the readIndex
  // returns -1 when there is no note available
  int getNote();
  // adds a note to the melody (only if 'spots' are available)
  void addNote(int note);
  void printList();
  void setLoop(bool loop);
protected:
  // integer array containing the note values
  std::vector<int> notes;
private:
  // read and write index
  int readIndex;
  bool loop = false;
};

#endif
