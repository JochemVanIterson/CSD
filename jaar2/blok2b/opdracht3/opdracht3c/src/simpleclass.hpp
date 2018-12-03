#ifndef _SIMPLECLASS_H
#define _SIMPLECLASS_H

class SimpleClass{
public:
  SimpleClass();
  SimpleClass(int privateInt);
  ~SimpleClass();

  int getPrivateInt();
  void setPrivateInt(int privateInt);
private:
  int privateInt;
};

#endif
