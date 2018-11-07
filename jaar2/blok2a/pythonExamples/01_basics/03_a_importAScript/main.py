"""
This is an example of a script that imports another script and uses its content.

This script imported another python script: 'textualSoundGenerator.py'.
This gives you access to the content of this external python script.

E.g. the 'textualSoundGenerator.py' script contains the function 'generateSound'.
The 'textualSoundGenerator.py' file can be imported as follows:
import textualSoundGenerator
The content of this script is now accible through the module 'textualSoundGenerator'.
Its function 'generateSound' can be called as follows:
textualSoundGenerator.generateSound()

------ HANDS-ON TIPS ------
You can also define the module name while importing a script / module:
import [script] as [moduleName]

1. Try to import the 'textualSoundGenerator.py' script under a different name
   and adapt the call to the 'generateSound()' function accordingly.
"""



#import another script
import textualSoundGenerator

#this script is imported as a module, we can print its type as follows
print("'textualSoundGenerator.py' is import as a " + type(textualSoundGenerator).__name__)

#The generateSound function returns a string, print it to the console
print(textualSoundGenerator.generateSound())
