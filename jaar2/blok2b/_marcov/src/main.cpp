#include <iostream>
#include <stdio.h>
#include <thread>

#include "midi/Options.h"

#include "jack/jack_module.h"
#include "melody/marcov.h"
#include "melody/midiplayer.h"
#include "tools/tools.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

// #define PI_2 6.28318530717959

int main(int argc,char **argv){
  smf::Options options;
  options.process(argc, argv);

  int marcovSize = 1;

  std::cout << "Note: " << 50 << " Freq: " << Tools::midinote2freq(50) << std::endl;

  // --------------------------------------- Parameters --------------------------------------- //
  std::string midiFileName = "";
  if (options.getArgCount() != 2){
    std::cout << "Midi File: ";
    std::cin >> midiFileName;

    std::cout << "Marcov type: ";
    std::cin >> marcovSize;
  } else {
    marcovSize = std::stoi(options.getArg(1));
    std::cout << "Marcov type: " << marcovSize << std::endl;

    midiFileName = options.getArg(2);
    std::cout << "Midi File: " << midiFileName << std::endl;
  }

  // --------------------------------------- Marcov melody --------------------------------------- //
  Marcov melodyMarcov(marcovSize);

  melodyMarcov.learnMarcov(midiFileName);
  melodyMarcov.initMelody();

  melodyMarcov.addNote();
  melodyMarcov.addNote();
  melodyMarcov.addNote();
  melodyMarcov.printList();
  std::cout << "Value: " << melodyMarcov.getNote() << std::endl;

  // --------------------------------------- Marcov melody --------------------------------------- //
  MidiPlayer melodyMidi(midiFileName);
  melodyMidi.printList();
  std::cout << "Value: " << melodyMidi.getNote() << std::endl;



  // --------------------------------------- Jack --------------------------------------- //
  /*
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  //assign a function to the JackModule::onProces
  jack.onProcess = [](jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      // calculate next sample
    }
    return 0;
  };
  jack.autoConnect();
  */
  // --------------------------------------- Jack --------------------------------------- //

  //keep the program running and listen for user input, q = quit
  std::cout << "Press 'q' when you want to quit the program." << std::endl;
  bool running = true;
  while (running){
    // Output prompt
    // std::cout << "Press any key to continue..." << std::endl;

    // Set terminal to raw mode
    // std::system("stty raw");

    // Wait for single character
    char input = std::getchar();
    if(input=='q'){
      running = false;
      // --------------------------------------- Jack --------------------------------------- //
      // jack.end();
      // --------------------------------------- Jack --------------------------------------- //
    }

    // Reset terminal to normal "cooked" mode
    // std::system("stty cooked");
  }

  //end the program
  return 0;
} // main()
