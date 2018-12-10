#include <iostream>
#include <thread>
#include "jack/jack_module.h"
#include "oscillator/subs/sine.h"
#include "oscillator/subs/saw.h"
#include "oscillator/subs/square.h"
#include "oscillator/subs/triangle.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv){
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  float frequency = 220;

  Oscillator* oscillator = new Sine(samplerate, frequency);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&oscillator](jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    static double amplitude = 0.5;

    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * oscillator->getSample();
      // calculate next sample
      oscillator->tick();
    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running){
    switch (std::cin.get()){
      case 'q':
        running = false;
        jack.end();
        delete oscillator;
        oscillator = nullptr;
        break;
      case '1':
        delete oscillator;
        oscillator = new Sine(samplerate, frequency);
        std::cout << "oscillator sine: " << oscillator << std::endl;
        break;
      case '2':
        delete oscillator;
        oscillator = new Saw(samplerate, frequency);
        std::cout << "oscillator saw: " << oscillator << std::endl;
        break;
      case '3':
        delete oscillator;
        oscillator = new Square(samplerate, frequency);
        std::cout << "oscillator square: " << oscillator << std::endl;
        break;
      case '4':
        delete oscillator;
        oscillator = new Triangle(samplerate, frequency);
        std::cout << "oscillator triangle: " << oscillator << std::endl;
        break;
    }
  }

  //end the program
  return 0;
} // main()
