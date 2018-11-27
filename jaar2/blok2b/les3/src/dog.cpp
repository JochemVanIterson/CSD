#include <iostream>
#include <string>

#include "dog.hpp"
#include "pet.hpp"

Dog::Dog(std::string name, int age):Pet(name, age){
  std::cout<<"Dog::Dog() - constructor"<<std::endl;
}
Dog::~Dog(){
  std::cout<<"Dog::Dog() - destructor"<<std::endl;
}

void Dog::bark(){
  std::cout<<"Dog::Dog() - bark"<<std::endl;
}
