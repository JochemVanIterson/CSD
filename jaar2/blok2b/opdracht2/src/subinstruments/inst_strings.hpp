#include "../instrument.hpp"

class InstStrings: public Instrument{
  public:
    // --------------------- Constructor and Destructor --------------------- //
    InstStrings();
    InstStrings(std::string name);
    ~InstStrings();

    // --------------------- Functions -------------------------------------- //
    bool makeSound(int note); // Overwrites
};
