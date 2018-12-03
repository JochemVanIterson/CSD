#include <iostream>

// Reference: http://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_pointerreference.html

void pointerfunction(std::string value, std::string *pointer, std::string &reference){
  std::cout << "pointerfunction input" << std::endl;
  std::cout << "\tvalue: " << value << std::endl;
  std::cout << "\tpointer: " << *pointer << std::endl;
  std::cout << "\treference: " << reference << std::endl;
  std::cout << std::endl;

  value = "Value Changed";
  *pointer = "Pointer Changed";
  reference = "Reference Changed";

  std::cout << "pointerfunction changed" << std::endl;
  std::cout << "\tvalue: " << value << std::endl;
  std::cout << "\tpointer: " << *pointer << std::endl;
  std::cout << "\treference: " << reference << std::endl;
  std::cout << std::endl;
}

int main() {
  std::string value = "Value";
  std::string pointerValue = "Pointer";
  std::string referenceValue = "Reference";
  std::cout << "main init" << std::endl;
  std::cout << "\tvalue: " << value << std::endl;
  std::cout << "\tpointer: " << pointerValue << std::endl;
  std::cout << "\treference: " << referenceValue << std::endl;
  std::cout << std::endl;

  pointerfunction(value, &pointerValue, referenceValue);

  std::cout << "main changed" << std::endl;
  std::cout << "\tvalue: " << value << std::endl;
  std::cout << "\tpointer: " << pointerValue << std::endl;
  std::cout << "\treference: " << referenceValue << std::endl;
  std::cout << std::endl;
}
