#include <iostream>
#include <string>

#include "mijnclass.hpp"

// Constructor and Destructor
MijnClass::MijnClass(){
  std::cout << "MijnClass::MijnClass() - Constructor" << std::endl;
  this->privateVar = 10;
  this->publicVar  = 20;
  print();
}
MijnClass::MijnClass(int privateVar, int publicVar){
  std::cout << "MijnClass::MijnClass(int private, int public) - Constructor" << std::endl;
  this->privateVar = privateVar;
  this->publicVar  = publicVar;
  print();
}
MijnClass::~MijnClass(){
  std::cout << "MijnClass::~MijnClass() - Destructor" << std::endl;
  print();
}

// Getters and Setters
int MijnClass::getPrivateVar(){
  return privateVar;
}
void MijnClass::setPrivateVar(int privateVar){
  this->privateVar = privateVar;
}

// Functions
void MijnClass::print(){
  std::cout << "void MijnClass::print() privateVar: " << privateVar;
  std::cout << " publicVar: " << publicVar << std::endl;
}
