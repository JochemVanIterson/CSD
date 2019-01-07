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

int keyOctave = 5;

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
  Tools::init_rand();

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

  Voice oscVoice(samplerate, "fm");
  Voice keyVoice(samplerate, "fm");

  //assign a function to the JackModule::onProces
  jack.onProcess = [&oscVoice, &keyVoice](jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // write sine output * amplitude --> to output buffer
      outBuf[i] = oscVoice.getSample() + keyVoice.getSample();
      // calculate next sample
      oscVoice.tick();
      keyVoice.tick();
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
    // Set terminal to raw mode
    std::system("stty raw");

    // Wait for single character
    char input = std::getchar();
    if(input=='q'){
      running = false;
      jack.end();
    } else if(input=='z'){
      keyOctave--;
    } else if(input=='x'){
      keyOctave++;
    } else if(input=='1'){
      oscVoice.setType("sine");
      keyVoice.setType("sine");
    } else if(input=='2'){
      oscVoice.setType("saw");
      keyVoice.setType("saw");
    } else if(input=='3'){
      oscVoice.setType("square");
      keyVoice.setType("square");
    } else if(input=='4'){
      oscVoice.setType("triangle");
      keyVoice.setType("triangle");
    } else if(input=='5'){
      oscVoice.setType("fm");
      keyVoice.setType("fm");
    } else {
      int keymidiValue = Tools::keymidi(input);
      if(keymidiValue!=-1){
        keyVoice.noteOn((12*keyOctave)+keymidiValue, .2, 200.);
      }
    }

    // Reset terminal to normal "cooked" mode
    std::system("stty cooked");
  }

  //end the program
  return 0;
} // main()
