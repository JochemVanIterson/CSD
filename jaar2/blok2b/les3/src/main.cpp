#include <iostream>
#include <string>

#include "pet.hpp"
#include "dog.hpp"

int main() {
  Dog dog("piet", 20);
  dog.eat();
  dog.bark();
  dog.sleep();
  dog.getVars();
  return 0;
}
