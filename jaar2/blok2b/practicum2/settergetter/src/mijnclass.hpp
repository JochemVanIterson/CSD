#ifndef MIJNCLASS_H
#define MIJNCLASS_H
class MijnClass{
  public:
    // Constructor and Destructor
    MijnClass(int privateVar, int publicVar);
    MijnClass();
    ~MijnClass();

    // Variables
    int publicVar;

    // Getters and Setters
    void setPrivateVar(int privateVar);
    int  getPrivateVar();

    // Functions
    void print();
  private:
    // Variables
    int privateVar;
};
#endif
