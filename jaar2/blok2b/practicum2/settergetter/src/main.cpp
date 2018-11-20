#include <iostream>
#include <string>

#include "mijnclass.hpp"

int main(){
  std::cout << "main()" << std::endl;
  MijnClass mijnClass(80, 40);
  mijnClass.print();
  mijnClass.publicVar = 20;
  mijnClass.setPrivateVar(1000);
  mijnClass.print();
  return 0;
}
