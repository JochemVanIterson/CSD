// Reference: https://www.tutorialspoint.com/cplusplus/

#include <iostream>
#include <string>

using namespace std; // Soort van class. Hiermee zeg je dat alle functies de prefix (class) 'std' moeten krijgen

extern string text; // maakt string text global, en toegankelijk voor externe files
string text = "Hello "; // Initialiseert een string met naam 'text' en waarde "Hello World :-)"
enum color { red, green = 5, blue } c; // Initialiseert een int waarin 'red' staat voor 0, 'green' staat voor 5, en 'blue' staat voor 2.

int main() {
  char name[50];
  int age;
  cout << "Input: "; // stringout
  cin >> name >> age;
  cout << "string: " << text << name << endl; // stringout
  cout << "age: " << age << endl; // stringout
  c = blue; // (lokale variabele) 'blue' is 2
  cout << "enum: " << c << endl; // stringout
  clog << "Error message : " << age << endl;
  return 0;
}
