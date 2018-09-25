import time
from threading import Thread

continueRunning = True

#a function that prints "bleep" to the console every second
def bleep():
  global continueRunning
  #repeat: wait 1 second, print "bleep" to console
  while continueRunning:
    time.sleep(1)
    print("bleep")



#start another thread
t = Thread(target=bleep)
t.start()

#ask user if we should continue or quit
while continueRunning:
  #NOTE: not using a lock currently, to keep the example simple
  continueRunning = input("Do you want to quit? y/n - ") != "y"

#wait until thread terminates
t.join()
