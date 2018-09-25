import numpy as np

#todo - move > Sine static value
twoPi = 2 * np.pi

class Sine:
  def __init__(self, audioSettings, frequency=220, amplitude = 0.5):
    self.phase = 0
    self.amplitude = amplitude
    self.frequency = frequency
    self.audioSettings = audioSettings
    #set default value
    self.value = 0


#TODO - add a Clock class & object to the project to which all audio objects
#listen, instead of the need to manualy call tick method

  def tick(self):
    """move sine a step forward"""
    #update phase according to sampleRate and frequency
    self.phase += twoPi * self.frequency / self.audioSettings.get('sampleRate')
    #calculate new sinewave value with update phase
    #As we are working with 16-bit integers, the range is from -32768 to 32767
    self.value = self.amplitude * np.sin(self.phase)
