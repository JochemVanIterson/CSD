"""
An example of a class with an initialize method.

A class is a template definition of the methods (=class functions) and attributes
(=class variables) of a particular object.
It is like a blueprint of the object. This blueprint allows you to create
multiple objects sharing the same design.


"The instantiation operation (“calling” a class object) creates an empty object.
Many classes like to create objects with instances customized to a specific
initial state. Therefore a class may define a special method named __init__(),
like this:
def __init__(self):
    self.data = []
"
Source lines 10 t/m 16 -> https://docs.python.org/3/tutorial/classes.html


------ HANDS-ON TIPS ------
1.  Change the sound attribute value (assign a new string to it) of the
    myInstrument object and then call the makeSound method another time. What do
    you expect to see in the console?
2.  The __init__ method exepts a string parameter, when you instantiate the
    object you can therefor pass it a string, e.g.:
    myInstrument = Instrument("Ploink!")
    Try this out, what do you expect to see in the console?
"""
#TODO - add more HANDS-ON TIPS



class Instrument:
  """A class - with which you can make textual instrument sounds."""

  def __init__(self, sound="*Pling*"):
    """The ___init___ method of the Instrument class."""
    print("- inside the __init__ method -")
    #init sound attribute (=class variable)
    self.sound = sound

  def makeSound(self):
    """The makeSound method produces a textual instrument sound"""
    print("- inside the makeSound method -")
    print("A sound is produced: " + self.sound)



#make an object of this class
myInstrument = Instrument()

#use the makeSound method
myInstrument.makeSound()

myInstrument.sound = "ffff"

#use the makeSound method
myInstrument.makeSound()
