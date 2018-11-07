import pyAudioWrapper
import time


#create a PyAudioWrapper object
wrapper = pyAudioWrapper.PyAudioWrapper()

#call displayDevices() to display all available in- and outputs
#wrapper.showDevices()

wrapper.startStream()


running = 1
while (running):
  if(input("Type 'q' to quit") == 'q'):
    running = 0

wrapper.stopStream()

#wait to be sure that audio stream is stopped
# TODO - is this necessary? can we check audiostream ourselves?
time.sleep(0.5)
