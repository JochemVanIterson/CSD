#import the array module
import array

"""
This is example of a script that imports a module and uses its content.

"The 'array' module defines an object type which can compactly represent an
array of basic values: characters, integers, floating point numbers.
Arrays are sequence types and behave very much like lists, except that the
type of objects stored in them is constrained. The type is specified at object
creation time by using a type code, which is a single character."
source: https://docs.python.org/3.6/library/array.html
"""

#Let's generate an array to hold integers.
#The 'i' type code corresponds to a signed int.
#The 'I' type code corresponds to an unsigned int.
#E.g. we create an array to hold a C major chord in midi-notes. No negative
#values are needed, we will therefor use 'i' as typecode.
midiArray = array.array('i', [60, 64, 67])
print(midiArray)
