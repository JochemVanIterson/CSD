"""
An example of a class.

A class is a template definition of the methods (=class functions) and attributes
(=class variables) of a particular object.
It is like a blueprint of the object. This blueprint allows you to create
multiple objects sharing the same design.

------ HANDS-ON TIPS ------
1.  You can display information about a class by using the standard function help.
    Try this out yourself, add the following line to the code:
    help(Instrument)
    You can quit help by pressing the [q] key
2.  Add another method (= class function) to the class and call it.
"""
#TODO - add more HANDS-ON TIPS



class Instrument:
  """A class - with which you can make textual instrument sounds."""

  def makeSound(self):
    """The makeSound method produces a textual instrument sound"""
    print("A sound is produced: *Pling* ")



#make an object of this class
myInstrument = Instrument()

#use the makeSound method
myInstrument.makeSound()
