#ifndef _MELODY_H
#define _MELODY_H

#define NUM_NOTES 10

#include <iostream>
#include <stdio.h>

class Melody
{
public:
  // constructor and destructor
  Melody();
  virtual ~Melody();

  // returns the note at the readIndex
  // returns -1 when there is no note available
  int getNote();
  // adds a note to the melody (only if 'spots' are available)
  void addNote(int note);
  void printList();

private:
  // integer array containing the note values
  int notes[NUM_NOTES] = {0};
  // read and write index
  int readIndex;
  int writeIndex;
};

#endif
