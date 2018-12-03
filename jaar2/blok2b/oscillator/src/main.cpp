#include <iostream>
#include <fstream>
#include <string>

#include "oscillator/sine.hpp"
#include "oscillator/oscillator.hpp"
#include "jack/jack_module.h"

#include <math.h>
#include <cmath>

int main(int argc,char **argv){
  std::cout << "main()" << std::endl;
  
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  std::cout << "samplerate: " << samplerate << std::endl;
  static Oscillator oscSine(samplerate, 220, 1.0, "sine");

  //assign a function to the JackModule::onProces
  jack.onProcess = [](jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = oscSine.calc();
      oscSine.tick();
    }
    return 0;
  };

  jack.autoConnect();

  int counter = 0;

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running) {
    counter++;
    // if((std::fmod(counter, samplerate))==0){
    //   int random = rand() % 440 + 220;
    //   oscSine.setFrequency(random);
    // }
    switch (std::cin.get()) {
      case 'q':
        running = false;
        break;
    }
  }

  return 0;
}
