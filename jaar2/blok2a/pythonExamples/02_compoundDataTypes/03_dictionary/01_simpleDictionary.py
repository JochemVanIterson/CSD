

#TODO - add information, comments, HANDS-ON TIPS
audioSettings = {
  'channels': 1,
  'sampleRate': 44100,
  'framesPerBuffer': 256
}


print(audioSettings)

print("There are different ways to retrieve a value, stored at a specific index.")
print("The value that is stored at the key 'channels': ", audioSettings['channels'])
print("The value that is stored at the key 'channels': ", audioSettings.get('channels'))
