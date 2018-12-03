#include <iostream>
#include <fstream>
#include <string>

#include "oscillator/generator.hpp"
#include "oscillator/oscillator.hpp"
#include "jack/jack_module.h"

#include <fstream>
#include <vector>

#include <math.h>
#include <cmath>

#include <getopt.h>
#include <stdlib.h>
#include <sstream>

void write2file(std::string filename, std::vector<double> buffer){
  std::ofstream myfile;
  myfile.open(filename);

  int counter = 0;
  for(double n : buffer) {
      myfile << counter << "," << n << '\n';
      counter++;
  }
  myfile.close();
}

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc,char **argv){
  std::string type = "sine";
  int frequency = 220;
  static bool debug = false;
  bool csvout = false;

  // ------------------ arguments input ------------------ //
  int c;
  while (1) {
    // int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
      {"frequency", required_argument,  0,  'f' },
      {"type",      required_argument,  0,  't' },
      {"debug",     no_argument,        0,   1  },
      {"csvout",    no_argument,        0,   2  },
      {0,           0,                  0,   0  }
    };

    c = getopt_long(argc, argv, "f:t:0", long_options, &option_index);
    if (c == -1)
      break;

    switch (c) {
      case 0:
        printf("option %s", long_options[option_index].name);
        if (optarg)
          printf(" with arg %s", optarg);
        printf("\n");
        break;

      case 'f':
        frequency = atoi(optarg);
        break;

      case 't':
        type = optarg;
        break;
      case 1: // debug
        debug = true;
        break;
      case 2: // debug
        csvout = true;
        break;

      case '?':
        printf("Unknown argument\n");
        exit(1);
        break;

      default:
        printf("?? getopt returned character code 0%o ??\n", c);
    }
  }
  if (optind < argc) {
    printf("non-option ARGV-elements: ");
    while (optind < argc)
      printf("%s ", argv[optind++]);
      printf("\n");
  }

  // ------------------ arguments log -------------------- //
  std::cout << "Settings:" << std::endl;
  std::cout << "\ttype: " << type  << std::endl;
  std::cout << "\tfrequency: " << frequency  << std::endl;
  std::cout << "\tdebug: " << debug  << std::endl;
  std::cout << "\tcsvout: " << csvout  << std::endl;
  std::cout << std::endl;

  // ------------------ CSV output -------------------- //
  if(csvout){
    int samplerate = 44100;
    static Oscillator oscSquare(samplerate, frequency, 1.0, type, debug);
    std::vector<double> outBuf;
    for(int walker = 0; walker<(samplerate*2); walker++){
      double calc = oscSquare.calc();
      // std::cout << "square: " << calc << std::endl;
      outBuf.push_back(calc);
      oscSquare.tick();
    }
    write2file("csvout.csv", outBuf);
    return 0; // exit program with state 0
  }

  JackModule jack;

  // init the jack, use program name as JACK client name
  if(jack.init(argv[0])){ // if jack.init() returns 1, jack not started successfully
    std::cout << "Jack not running, exiting" << std::endl;
    return(1);
  }
  double samplerate = jack.getSamplerate();
  if(debug)std::cout << "samplerate: " << samplerate << std::endl;
  static Oscillator oscSine(samplerate, frequency, 1.0, type, debug);

  //assign a function to the JackModule::onProces
  jack.onProcess = [](jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = oscSine.calc();
      oscSine.tick();
    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "Press 'q' when you want to quit the program.\n";
  bool running = true;
  while (running) {
    std::string cinValue;
    std::cin >> cinValue;

    std::vector<std::string> splitElements = split(cinValue,' ');

    std::string token = splitElements.at(0);
    std::cout << "Input: " << cinValue << std::endl;
    std::cout << "Token: " << token << std::endl;
    std::cout << "Value: " << splitElements.at(1) << std::endl;
    // std::string token = cinValue.substr(0, cinValue.find(delimiter));

    if(token=="q"){
      running = false;
      break;
    } else if(token=="freq"){
      // std::string value = splitElements.at(1);
      // std::cout << "Frequency: " << splitElements << std::endl;
    }
  }

  return 0;
}
