#
# Basic pyaudio-wrapper
#

import pyaudio
import array
import audioProcessor



#store needed audio settings inside a global dictionary
AUDIOSETTINGS = {
  'width': 2,
  'channels': 1,
  'sampleRate': 44100,
  'framesPerBuffer': 256
}


audioProcessor = audioProcessor.AudioProcessor(AUDIOSETTINGS)


#todo - move ->  static attribute of PyAudioWrapper?
outbuf = array.array('h',range(AUDIOSETTINGS.get('framesPerBuffer'))) # array of signed ints

#todo - move ->  static method of PyAudioWrapper?
def audioCallback(in_data,frame_count,time_info,status):
  """The audio callback called by pyaudio whenever it needs output-data or
  has input-data. """

  global outbuf, phase, synth
  for n in range(frame_count):
    #call audioProcessor process method, no input -> pass 0
    #As we are working with 16-bit integers, the range is from -32768 to 32767
    outbuf[n] = int(32767 *  audioProcessor.process(0))

  return (outbuf.tobytes(), pyaudio.paContinue)


#TODO - rewrite PyAudioWrapper as a Singleton
class PyAudioWrapper:
  """A wrapper for pyaudio, to simplify its usage"""

  def __init__(self):
    """The ___init___ method of the pyAudioWrapper class."""

    #the interface to PortAudio
    self.paInterface = pyaudio.PyAudio()
    #init outputDeviceIndex and set it to the default output device
    defaultOutputInfo = self.paInterface.get_default_output_device_info()
    #retrieve the index of the default output and assign it to outputDeviceIndex
    self.outputDeviceIndex = defaultOutputInfo['index']


  def showDevices(self):
    """Lists available input- and output devices
    parameter paInterface - Interface to the pyaudio interface."""
    print(self)
    #retrieve PortAudio Host API info at index 0
    info = self.paInterface.get_host_api_info_by_index(0)
    #retrieve the number of available devices at PortAudio HOST API at index 0
    numdevices = info.get('deviceCount')
    for i in range (0,numdevices):
      #retrieve device parameters at index i
      deviceParameters = self.paInterface.get_device_info_by_host_api_device_index(0,i)
      #display the number of input and/or output channels
      if deviceParameters.get('maxInputChannels')>0:
        print("Input Device id ", i, " - ", deviceParameters.get('name'))
      if deviceParameters.get('maxOutputChannels')>0:
        print("Output Device id ", i, " - ", deviceParameters.get('name'))


  def showDefaultOutputDevice(self):
    """Displays default output device information"""
    #retrieve and display the default output Device info
    defaultOutputInfo = self.paInterface.get_default_output_device_info()
    print(defaultOutputInfo)


  def startStream(self):
    """Starts the audio stream."""
    format = format=self.paInterface.get_format_from_width(AUDIOSETTINGS.get('width'))
    self.stream = self.paInterface.open(format=format,
    		channels=AUDIOSETTINGS.get('channels'),
    		rate=AUDIOSETTINGS.get('sampleRate'),
    		frames_per_buffer=AUDIOSETTINGS.get('framesPerBuffer'),
    		input=False, # no input
    		output=True, # only output
    		output_device_index=self.outputDeviceIndex, # choose output device
    		stream_callback=audioCallback)

    self.stream.start_stream()


  def stopStream(self):
    """Stops the audio stream."""
    self.stream.stop_stream()
    self.stream.close()
    self.stream = None
