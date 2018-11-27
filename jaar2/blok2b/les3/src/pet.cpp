#include <iostream>

#include "pet.hpp"

Pet::Pet(std::string name, int age) {
  this->name = name;
  this->age = age;
  std::cout<<"Pet::Pet() - constructor"<<std::endl;
}
Pet::~Pet() {
  std::cout<<"Pet::Pet() - destructor"<<std::endl;
}

void Pet::eat(){
  std::cout<<"Pet::Pet() - eat"<<std::endl;
}
void Pet::sleep(){
  std::cout<<"Pet::Pet() - sleep"<<std::endl;
}

void Pet::getVars(){
  std::cout<<"Pet::Pet()"<<std::endl;
  std::cout<<"\tname = "<<name<<std::endl;

  std::cout<<"\tage  = "<<age<<std::endl;
}
