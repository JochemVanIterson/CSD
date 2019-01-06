#include <iostream>
#include <stdio.h>
#include <thread>

#include "midi/Options.h"

#include "jack/jack_module.h"
#include "melody/marcov.h"
#include "melody/midiplayer.h"
#include "tools/tools.h"
#include "threadTimer/threadTimer.h"

#include "oscillators/voice.h"

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

  // --------------------------------------- Parameters --------------------------------------- //
  int marcovSize = 1;
  std::string midiFileName = "";
  if (options.getArgCount() == 0){
    std::cout << "Midi File: ";
    std::cin >> midiFileName;

    std::cout << "Marcov type: ";
    std::cin >> marcovSize;
  } else if (options.getArgCount() != 2){
    std::cout << "Usage: " << options.getArg(0) << " <marcovSize> <midifile>" << std::endl;
    return(0);
  } else {
    marcovSize = std::stoi(options.getArg(1));
    std::cout << "Marcov type: " << marcovSize << std::endl;

    midiFileName = options.getArg(2);
    std::cout << "Midi File: " << midiFileName << std::endl;
  }

  std::cout << "Note: " << 50 << " Freq: " << Tools::midinote2freq(50) << std::endl;

  // --------------------------------------- Marcov melody --------------------------------------- //
  Marcov melodyMarcov(marcovSize);

  melodyMarcov.learnMarcov(midiFileName);
  melodyMarcov.initMelody();

  // --------------------------------------- Midi melody --------------------------------------- //
  MidiPlayer melodyMidi(midiFileName);
  melodyMidi.printList();

  Sequencer sequencer;

  // --------------------------------------- Jack --------------------------------------- //
  JackModule jack; // create a JackModule instance
  jack.init(argv[0]); // init the jack, use program name as JACK client name
  double samplerate = jack.getSamplerate();

  Voice oscVoice(samplerate, "sine");
  // oscVoice.noteOn(64, 1.);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&oscVoice](jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    static double amplitude = 0.5;

    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = amplitude * oscVoice.getSample();
      // calculate next sample
      oscVoice.tick();
    }
    return 0;
  };
  jack.autoConnect();

  ThreadTimer timer(&sequencer, &melodyMarcov, &oscVoice, 500.0);
  timer.startThread();

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
      jack.end();
    }

    // Reset terminal to normal "cooked" mode
    // std::system("stty cooked");
  }

  //end the program
  return 0;
} // main()
