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
  double frequency = 220;
  double amplitude = 1.0;
  std::string type = "sine";
  static bool debug = false;
  bool csvout = false;

  // ------------------ arguments input ------------------ //
  int c;
  while (1) {
    // int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
      {"frequency", required_argument,  0,  'f' },
      {"amplitude", required_argument,  0,  'a' },
      {"type",      required_argument,  0,  't' },
      {"debug",     no_argument,        0,   1  },
      {"csvout",    no_argument,        0,   2  },
      {0,           0,                  0,   0  }
    };

    c = getopt_long(argc, argv, "f:a:t:0", long_options, &option_index);
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
        frequency = atof(optarg);
        break;
      case 'a':
        amplitude = atof(optarg);
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
  std::cout << "   frequency: " << frequency << std::endl;
  std::cout << "   amplitude: " << amplitude << std::endl;
  std::cout << "   type: " << type  << std::endl;
  std::cout << "   debug: " << (debug?"true":"false") << std::endl;
  std::cout << "   csvout: " << (csvout?"true":"false")  << std::endl;
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
  static Oscillator oscSine(samplerate, frequency, amplitude, type, debug);

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
  std::cout << "Options:" << std::endl;
  std::cout << "   Set frequency:\tfreq <value>" << std::endl;
  std::cout << "   Set amplitude:\tamp <value>" << std::endl;
  std::cout << "   Set waveform:\ttype <sine|square|saw|triangle|m_square|m_saw>" << std::endl;
  std::cout << "   Set debug:\t\tdebug <true|false>" << std::endl;
  std::cout << "   Quit program:\tq|quit|exit" << std::endl;
  bool running = true;
  while (running) {
    std::string cinValue;
    std::cout << ":";
    getline(std::cin, cinValue);
    std::vector<std::string> splitElements = split(cinValue,' ');

    std::string token = splitElements[0];

    if(token=="q"|token=="quit"|token=="exit"){
      running = false;
      break;
    }

    std::string value = splitElements[1];
    if(token=="freq"){
      oscSine.setFrequency(std::stod(value));
      if(debug)std::cout << "Frequency: " << value << std::endl;
    } else if(token=="amp"){
      oscSine.setAmplitude(std::stod(value));
      if(debug)std::cout << "Amplitude: " << value << std::endl;
    } else if(token=="type"){
      type = value;
      oscSine.setType(type);
      if(debug)std::cout << "Waveform: " << value << std::endl;
    } else if(token=="debug"){
      if(value=="true")debug=true;
      else if(value=="false")debug=false;
      oscSine.setDebug(debug);
      if(debug)std::cout << "Debug: " << (debug?"true":"false") << std::endl;
    }
  }
  return 0;
}
