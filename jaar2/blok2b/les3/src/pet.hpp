#ifndef PET_H
#define PET_H

class Pet {
  public:
    // Constructor and Destructor
    Pet(std::string name, int age);
    ~Pet();

    // Funcitions
    void eat();
    void sleep();
    void getVars();
  protected:
    //Vars
    std::string name;
    int age;
};

#endif
