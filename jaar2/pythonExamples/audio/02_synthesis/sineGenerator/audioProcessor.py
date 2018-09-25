import sineGenerator

class AudioProcessor:
    def __init__(self, audioSettings):
      self.audioSettings = audioSettings
      self.sine = sineGenerator.Sine(audioSettings)

    def process(self, inputFrame):
      #move sine a step forward
      self.sine.tick()

      #retrieve the new value
      return self.sine.value
