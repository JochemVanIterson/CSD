#include <iostream>
#include "simpleclass.hpp"

int main() {
  std::cout << "int main()" << std::endl;

  std::cout << "---------------------- Static ----------------------" << std::endl;
  SimpleClass simpleclass1(1);
  SimpleClass simpleclass2(2);
  SimpleClass simpleclass3(3);
  SimpleClass simpleclass4(4);

  SimpleClass *simpleclass2Pointer = &simpleclass2;
  std::cout << "BEFORE" << std::endl;
  std::cout << "\tPOINTER getPrivateInt: " << simpleclass2Pointer->getPrivateInt() << std::endl;
  std::cout << "\tOBJECT  getPrivateInt: " << simpleclass2.getPrivateInt() << std::endl;
  simpleclass2Pointer->setPrivateInt(22);

  std::cout << "AFTER" << std::endl;
  std::cout << "\tPOINTER getPrivateInt: " << simpleclass2Pointer->getPrivateInt() << std::endl;
  std::cout << "\tOBJECT  getPrivateInt: " << simpleclass2.getPrivateInt() << std::endl;

  std::cout << "---------------------- Generative ----------------------" << std::endl;
  const int amound = 10;
  SimpleClass *loadsOfSimpleClass[amound];

  std::cout << "INIT" << std::endl;
  for (int i = 0; i < amound; i++) {
    loadsOfSimpleClass[i] = new SimpleClass(i);
  }
  std::cout << "OUTPUT" << std::endl;
  for (int i = 0; i < amound; i++) {
    std::cout << "("<<i<<")\t getPrivateInt: " << loadsOfSimpleClass[i]->getPrivateInt() << std::endl;
  }
  std::cout << "CHANGE" << std::endl;
  for (int i = 0; i < amound; i++) {
    loadsOfSimpleClass[i]->setPrivateInt(i+1000);
  }
  std::cout << "OUTPUT" << std::endl;
  for (int i = 0; i < amound; i++) {
    std::cout << "("<<i<<")\t getPrivateInt: " << loadsOfSimpleClass[i]->getPrivateInt() << std::endl;
  }

  return 0;
}
