#include <map>
#include "note2midi.h"

int note2midi::c(std::string input){
  std::map<std::string, int> database = note2midi::initDB();
  if (database.count(input) == 0)
		return -1;
	else
		return (*database.find(input)).second;
}

std::map<std::string, int> note2midi::initDB(){
  std::map<std::string, int> database;
  database["C-2"]  = 0;
  database["C#-2"] = 1;
  database["D-2"]  = 2;
  database["D#-2"] = 3;
  database["E-2"]  = 4;
  database["F-2"]  = 5;
  database["F#-2"] = 6;
  database["G-2"]  = 7;
  database["G#-2"] = 8;
  database["A-2"]  = 9;
  database["A#-2"] = 10;
  database["B-2"]  = 11;

  database["C-1"]  = 12;
  database["C#-2"] = 13;
  database["D-1"]  = 14;
  database["D#-1"] = 15;
  database["E-1"]  = 16;
  database["F-1"]  = 17;
  database["F#-1"] = 18;
  database["G-1"]  = 19;
  database["G#-1"] = 20;
  database["A-1"]  = 21;
  database["A#-1"] = 22;
  database["B-1"]  = 23;

  database["C0"]   = 24;
  database["C#0"]  = 25;
  database["D0"]   = 26;
  database["D#0"]  = 27;
  database["E0"]   = 28;
  database["F0"]   = 29;
  database["F#0"]  = 30;
  database["G0"]   = 31;
  database["G#0"]  = 32;
  database["A0"]   = 33;
  database["A#0"]  = 34;
  database["B0"]   = 35;

  database["C1"]   = 36;
  database["C#1"]  = 37;
  database["D1"]   = 38;
  database["D#1"]  = 39;
  database["E1"]   = 40;
  database["F1"]   = 41;
  database["F#1"]  = 42;
  database["G1"]   = 43;
  database["G#1"]  = 44;
  database["A1"]   = 45;
  database["A#1"]  = 46;
  database["B1"]   = 47;

  database["C2"]   = 48;
  database["C#2"]  = 49;
  database["D2"]   = 50;
  database["D#2"]  = 51;
  database["E2"]   = 52;
  database["F2"]   = 53;
  database["F#2"]  = 54;
  database["G2"]   = 55;
  database["G#2"]  = 56;
  database["A2"]   = 57;
  database["A#2"]  = 58;
  database["B2"]   = 59;

  database["C3"]   = 60;
  database["C#3"]  = 61;
  database["D3"]   = 62;
  database["D#3"]  = 63;
  database["E3"]   = 64;
  database["F3"]   = 65;
  database["F#3"]  = 66;
  database["G3"]   = 67;
  database["G#3"]  = 68;
  database["A3"]   = 69;
  database["A#3"]  = 70;
  database["B3"]   = 71;

  database["C4"]   = 72;
  database["C#4"]  = 73;
  database["D4"]   = 74;
  database["D#4"]  = 75;
  database["E4"]   = 76;
  database["F4"]   = 77;
  database["F#4"]  = 78;
  database["G4"]   = 79;
  database["G#4"]  = 80;
  database["A4"]   = 81;
  database["A#4"]  = 82;
  database["B4"]   = 83;

  database["C5"]   = 84;
  database["C#5"]  = 85;
  database["D5"]   = 86;
  database["D#5"]  = 87;
  database["E5"]   = 88;
  database["F5"]   = 89;
  database["F#5"]  = 90;
  database["G5"]   = 91;
  database["G#5"]  = 92;
  database["A5"]   = 93;
  database["A#5"]  = 94;
  database["B5"]   = 95;

  database["C6"]   = 96;
  database["C#6"]  = 97;
  database["D6"]   = 98;
  database["D#6"]  = 99;
  database["E6"]   = 100;
  database["F6"]   = 101;
  database["F#6"]  = 102;
  database["G6"]   = 103;
  database["G#6"]  = 104;
  database["A6"]   = 105;
  database["A#6"]  = 106;
  database["B6"]   = 107;

  database["C7"]   = 108;
  database["C#7"]  = 109;
  database["D7"]   = 110;
  database["D#7"]  = 111;
  database["E7"]   = 112;
  database["F7"]   = 113;
  database["F#7"]  = 114;
  database["G7"]   = 115;
  database["G#7"]  = 116;
  database["A7"]   = 117;
  database["A#7"]  = 118;
  database["B7"]   = 119;

  database["C8"]   = 120;
  database["C#8"]  = 121;
  database["D8"]   = 122;
  database["D#8"]  = 123;
  database["E8"]   = 124;
  database["F8"]   = 125;
  database["F#8"]  = 126;
  database["G8"]   = 127;
  return database;
}
