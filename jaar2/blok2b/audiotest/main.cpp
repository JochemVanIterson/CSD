#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  std::cout << "samplerate: " << samplerate << std::endl;
  //assign a function to the JackModule::onProces
  jack.onProcess = [samplerate](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static double phase1 = 0;
    static double phase2 = 0;
    static double amplitude = 0.5;
    static double frequency1 = 880;
    static double frequency2 = 660;

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = (amplitude/2 * sin(phase1 * PI_2 )) + (amplitude/2 * sin(phase2 * PI_2 ));
      phase1 += frequency1 / samplerate;
      phase2 += frequency2 / samplerate;
    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        break;
    }
  }

  //end the program
  return 0;
} // main()
