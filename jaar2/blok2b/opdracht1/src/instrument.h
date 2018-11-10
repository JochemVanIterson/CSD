class Instrument {
  public:
    bool makeSound();
    bool roll(int amound);
    Instrument(std::string soundid); // constructor
  private:
    std::string sound;
};
