#ifndef INSTRUMENT_H
#define INSTRUMENT_H

class Instrument {
  public:
    // --------------------- Constructor and Destructor --------------------- //
    Instrument(std::string name, int rngLow, int rngHigh); // constructor
    Instrument();
    ~Instrument();

    // --------------------- Functions -------------------------------------- //
    bool makeSound(int note);
    bool roll(int note, int amound);
  protected:
    // --------------------- Vars ------------------------------------------- //
    std::string name;
    int rangeLow;
    int rangeHigh;
};

#endif
