#include <iostream>
#include "dbgPrint.hpp"

void dbgPrint::d(std::string key, std::string message){
  std::cout << key << ": "  << message << std::endl; // dbg out
}
void dbgPrint::e(std::string key, std::string message){
  std::cout << "\033[1;31m" << key << ": " << "\033[0m" << message << std::endl; // dbg out
}
