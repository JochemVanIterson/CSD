#include "tools.h"

std::string Tools::array2string(std::vector<int> &writableArray, char delimiter){
  std::string stringValue = "";
  for(int walker = 0; walker<writableArray.size(); walker++){
    if(stringValue != "")stringValue+=delimiter;
    stringValue.append(std::to_string(writableArray[walker]));
  }
  return stringValue;
}
std::vector<int> Tools::string2array(std::string &s, char delimiter){
  std::vector<int> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  while (std::getline(tokenStream, token, delimiter)){
    tokens.push_back(std::stoi(token));
  }
  return tokens;
}
void Tools::array_insert_end(std::vector<int> &array, int maxsize, int value){
  for(int walker = 1; (walker<maxsize); walker++){
    array[walker-1] = array[walker];
  }
  if(array.size()<maxsize)array.push_back(value);
  else array[maxsize-1] = value;
}
int Tools::rand_between(int min, int max){
  srand(time(NULL));
  int size = max - min;
  return min+rand()%size;
}
void Tools::printVectorInt(std::string name, std::vector<int> &array){
  std::cout << "Name: " << name << std::endl;
  std::cout << "Size: " << array.size() << std::endl;
  for(int walker = 0; walker<array.size(); walker++){
    std::cout << array[walker] << ", ";
  }
  std::cout << std::endl;
}
