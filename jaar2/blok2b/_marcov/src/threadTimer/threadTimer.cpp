#include "threadTimer.h"

ThreadTimer::ThreadTimer(Sequencer *sequencer, MelodyProvider *provider, Voice *oscVoice, double delayTime){
  this->delayTime = delayTime;
  this->sequencer = sequencer;
  this->provider = provider;
  this->oscVoice = oscVoice;
}

ThreadTimer::~ThreadTimer(){
  if(running)stopThread();
}

void ThreadTimer::startThread() {
  running = true;
  thisThread = std::thread( [=] { threadCallable(); } );
}

void ThreadTimer::stopThread() {
  running = false;
  thisThread.join();
}

void ThreadTimer::threadCallable(){
  using namespace std::this_thread;     // sleep_for, sleep_until
  using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
  using std::chrono::system_clock;
  while(running){
    int newBufNote = provider->getNote();
    if(newBufNote!=-1)sequencer->addNote(newBufNote);

    int newPlayNote = sequencer->getNote();
    if(newPlayNote!=-1)oscVoice->noteOn(newPlayNote, 1., 400.0);

    sleep_for(delayTime*(1ms));
  }
}
