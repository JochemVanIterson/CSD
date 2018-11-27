#include "pet.hpp"

class Dog: public Pet{
  public:
    // Constructor and Destructor
    Dog(std::string name, int age);
    ~Dog();

    // Funcitions
    void bark();
};
