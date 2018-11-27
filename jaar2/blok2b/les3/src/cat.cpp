#include <iostream>
#include <string>

#include "cat.hpp"
#include "pet.hpp"

Cat::Cat(std::string name, int age):Pet(name, age){
  std::cout<<"Cat::Cat() - constructor"<<std::endl;
}
Cat::~Cat(){
  std::cout<<"Cat::Cat() - destructor"<<std::endl;
}

void Cat::climb(){
  std::cout<<"Cat::Cat() - bark"<<std::endl;
}
