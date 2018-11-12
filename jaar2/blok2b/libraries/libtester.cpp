#include "dbgPrint/dbgPrint.cpp"
#include "note2midi/note2midi.cpp"

int main(){
  int note0 = note2midi::c("B4");
  dbgPrint::e("note0", std::to_string(note0));
  return 0;
}
