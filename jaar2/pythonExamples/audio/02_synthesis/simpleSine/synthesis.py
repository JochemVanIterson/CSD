#
# Basic pyaudio program playing a real time mono sine wave
#
# (ME) 2015 Marc Groenewegen
#

import pyaudio
import time
import numpy as np
import array

# AUDIO SETTINGS
# sample size in bytes
WIDTH = 2
CHANNELS = 1
SAMPLERATE = 44100
FRAMESPERBUFFER = 256

#calculate 2 * pi value only once -> store it to variable
twoPi = 2*np.pi
#the frequency of the sinewave
sineFrequency = 520.0
#the phase of the sineWave
sinePhase=0
#the index to the outputDevice
outputDeviceIndex = 0


#
# Function showDevices() lists available input- and output devices
#
def showDevices(paInterface):
  #retrieve PortAudio Host API info at index 0
  info = paInterface.get_host_api_info_by_index(0)
  #retrieve the number of available devices at PortAudio HOST API at index 0
  numdevices = info.get('deviceCount')
  for i in range (0,numdevices):
    #retrieve device parameters at index i
    deviceParameters = paInterface.get_device_info_by_host_api_device_index(0,i)
    #display the number of input and/or output channels
    if deviceParameters.get('maxInputChannels')>0:
      print("Input Device id ", i, " - ", deviceParameters.get('name'))
    if deviceParameters.get('maxOutputChannels')>0:
      print("Output Device id ", i, " - ", deviceParameters.get('name'))

#
# Function showDefaultOutputDevice displays the default output
#
def showDefaultOutputDevice(paInterface):
  """Displays default output device information"""
  #retrieve and display the default output Device info
  defaultOutputInfo = paInterface.paInterface.get_default_output_device_info()
  print(defaultOutputInfo)

#
# Function selectDefaultOutputDevice selects the default output
#
def selectDefaultOutputDevice(paInterface):
  global outputDeviceIndex
  # init outputDeviceIndex and set it to the default output device
  defaultOutputInfo = paInterface.get_default_output_device_info()
  outputDeviceIndex = defaultOutputInfo['index']


def setOutputDevice(paInterface):
  global outputDeviceIndex
  info = paInterface.get_host_api_info_by_index(0)
  numdevices = info.get('deviceCount')
  for i in range (0,numdevices):
    print("maxOutputChannels at index ", i , ": ", paInterface.get_device_info_by_host_api_device_index(0,i).get('maxOutputChannels'))
    if paInterface.get_device_info_by_host_api_device_index(0,i).get('maxOutputChannels')>0:
      # select ouput device by checking its name: contains "Built-in"? (edit string to select e.g. 'pulse')
      if paInterface.get_device_info_by_host_api_device_index(0,i).get('name').find("Built-in") >= 0:
        outputDeviceIndex=i

  print("Selected device number: ", str(outputDeviceIndex))


#
# Create array of signed ints to hold one sample buffer
# Make it global so it doesn't get re-allocated for every frame
#
outbuf = array.array('h',range(FRAMESPERBUFFER)) # array of signed ints


#
# Create the callback function which is called by pyaudio
#   whenever it needs output-data or has input-data
#
# As we are working with 16-bit integers, the range is from -32768 to 32767
#
def callback(in_data,frame_count,time_info,status):
  global sinePhase
  global outbuf
  for n in range(frame_count):
    outbuf[n] = int(32767 * 0.5 * np.sin(sinePhase))
    sinePhase += twoPi * sineFrequency / SAMPLERATE
  return (outbuf.tobytes(), pyaudio.paContinue)


	  #########################
	  # Start of main program #
	  #########################


#
# get a handle to the pyaudio interface
#
paInterface = pyaudio.PyAudio()
print("\nAvailable devices: ")
showDevices(paInterface)
print("\n")
# select default output device
selectDefaultOutputDevice(paInterface)
# displayed selected device
devinfo = paInterface.get_device_info_by_index(outputDeviceIndex)
print("Selected device name: ",devinfo.get('name'))



#
# open a stream with some given properties
#
stream = paInterface.open(format=paInterface.get_format_from_width(WIDTH),
		channels=CHANNELS,
		rate=SAMPLERATE,
		frames_per_buffer=FRAMESPERBUFFER,
		input=False, # no input
		output=True, # only output
		output_device_index=outputDeviceIndex, # choose output device
		stream_callback=callback)


# start audio stream
stream.start_stream()

# Make sure that the main program doesn't finish until all
#  audio processing is done
while stream.is_active():
  time.sleep(1)


# in this example you'll never get here
stream.stop_stream()
stream.close()

paInterface.terminate()
