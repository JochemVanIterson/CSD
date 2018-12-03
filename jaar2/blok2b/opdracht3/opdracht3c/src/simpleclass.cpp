#include "simpleclass.hpp"
#include <iostream>

SimpleClass::SimpleClass(){
  // std::cout << "SimpleClass::SimpleClass() Constructor" << std::endl;
}
SimpleClass::~SimpleClass(){
  // std::cout << "SimpleClass::SimpleClass() Destructor" << std::endl;
}

SimpleClass::SimpleClass(int privateInt){
  // std::cout << "SimpleClass::SimpleClass() Constructor privateInt: " << privateInt << std::endl;
  this->privateInt = privateInt;
}

int SimpleClass::getPrivateInt(){
  return privateInt;
}
void SimpleClass::setPrivateInt(int privateInt){
  this->privateInt = privateInt;
}
