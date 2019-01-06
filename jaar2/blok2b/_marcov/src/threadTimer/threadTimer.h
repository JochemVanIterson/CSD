#ifndef _THREADTIMER_H_
#define _THREADTIMER_H_

#include "../melody/melody_provider.h"
#include "../melody/sequencer.h"
#include "../oscillators/voice.h"

#include <chrono>
#include <thread>

class ThreadTimer{
public:
  ThreadTimer(Sequencer *sequencer, MelodyProvider *provider, Voice *oscVoice, double delayTime);
  ~ThreadTimer();

  void startThread();
  void stopThread();
  bool threadIsRunning();
private:
  double delayTime = 1000;
  bool running = false;
  std::thread thisThread;

  Sequencer *sequencer;
  MelodyProvider *provider;
  Voice *oscVoice;
  void threadCallable();
};

#endif
