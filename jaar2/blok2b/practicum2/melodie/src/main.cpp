#include <iostream>
#include <string>

#include "melody.hpp"

int main(){
  std::cout << "main()" << std::endl;

  Melody melody;
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // leeg -> -1
  melody.addNote(34);
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // 34
  melody.addNote(47);
  melody.addNote(95);
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // 47
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // 95
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // leeg -> -1
  melody.addNote(54);
  melody.addNote(73);
  melody.addNote(32);
  melody.addNote(87);
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // 54
  melody.addNote(36);
  melody.printList();
  melody.addNote(47);

  melody.addNote(-97);
  melody.addNote(97);
  melody.addNote(62);
  melody.addNote(15);
  melody.printList();
  melody.addNote(58);
  melody.addNote(89); // Error
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // 73
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // 32
  std::cout << "melody.getNote(): " << melody.getNote() << std::endl; // 87
  melody.addNote(10);
  melody.addNote(11);

  melody.printList();

  return 0;
}
