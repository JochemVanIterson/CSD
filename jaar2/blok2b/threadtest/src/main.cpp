#include <iostream>
#include <thread>
#include <string>

#include <chrono>

int main() {
  bool running = true;
  std::thread threadObj([&running]{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
    std::cout<<"Display Thread Executing Start"<<std::endl;

    while(running){
      sleep_for(1ms);
      std::cout<<"Display Thread Executing Loop"<<std::endl;
    }
    std::cout<<"Display Thread Executing End"<<std::endl;
    // for(int i = 0; i < 10; i++){
    //   std::cout<<"Display Thread Executing"<<std::endl;
    // }
  });
  std::string stopvalue;
  std::cin >> stopvalue;
  if(stopvalue=="q"){
    running = false;
    threadObj.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
  }
  return 0;
}
