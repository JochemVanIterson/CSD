#include <iostream>


int main()
{
char letter = 97;
char *letterpointer;

  std::cout << "Contents of the variable letter: ";
  std::cout << letter << std::endl;
  // -- your code here --

  letterpointer = &letter;
  std::cout << "Contents of letterpointer: ";
  std::cout << std::hex << (unsigned long)letterpointer << std::dec << std::endl;
  // -- your code here --

  std::cout << "Contents of what letterpointer points to: ";
  std::cout << *letterpointer << std::endl;
  // -- your code here --

  *letterpointer = 'b';
  std::cout << "The variabele letter has gotten a new value through letterpointer. ";
  std::cout << "Contents of what letterpointer points to: ";
  std::cout << *letterpointer << std::endl;
  // -- your code here --

  std::cout << "Contents of the variable letter: ";
  std::cout << letter << std::endl;
  std::cout << std::endl;
  // -- your code here --


  /*
   * Create the necessary pointer(s) and use them
   */

  unsigned short year = 2018;
  unsigned short *yearPointer;
  std::cout << "Contents of the variabele year: ";
  std::cout << year << std::endl;

  // create a pointer to year
  // -- your code here --
  yearPointer = &year;

  std::cout << "Contents of yearpointer: ";
  std::cout << std::hex << (unsigned long)yearPointer << std::dec << std::endl;
  // -- your code here --

  std::cout << "Contents of what yearpointer points to: ";
  std::cout << *yearPointer << std::endl;

  *yearPointer = 7856;
  // give year a new value via yearpointer
  // -- your code here --

  std::cout << "Contents of the variabele year: ";
  std::cout << year << std::endl;
  // -- your code here --


  // create another pointer to year, named anotheryearpointer
  // -- your code here --
  unsigned short *anotheryearpointer;
  anotheryearpointer = &year;

  std::cout << "Contents of anotheryearpointer: ";
  std::cout << std::hex << (unsigned long)anotheryearpointer << std::dec << std::endl;
  // -- your code here --
  std::cout << "Contents of what anotheryearpointer points to: ";
  std::cout << *anotheryearpointer << std::endl;
  // -- your code here --

  // give year a new value via anotheryearpointer
  *yearPointer = 9780;
  // -- your code here --

  std::cout << "Contents of year: ";
  std::cout << year << std::endl;
  // -- your code here --

  std::cout << "Contents of what anotheryearpointer points to: ";
  std::cout << *anotheryearpointer << std::endl;
  // -- your code here --

} // main()
