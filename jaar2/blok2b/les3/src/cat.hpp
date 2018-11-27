#include "pet.hpp"

class Cat: public Pet{
  public:
    // Constructor and Destructor
    Cat(std::string name, int age);
    ~Cat();

    // Funcitions
    void climb();
};
