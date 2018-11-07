"""
This script contains a simple example of working with arrays.
"""

#import the array module
import array

#Let's generate an array to hold integers.
#The 'i' type code corresponds to a signed int.
#The 'I' type code corresponds to an unsigned int.
#E.g. we create an array to hold a C major chord in midi-notes. No negative
#values are needed, we will therefor use 'i' as typecode.
chordArray = array.array('i', [60, 64, 67])
print("The array chordArray:", chordArray)

#access content of the array at a specific index
print("\nAt index 1, chordArray contains:", chordArray[1])

#alter content at a specific index
chordArray[1] = 63
print("\nAltered content at index 1, this now contains:", chordArray[1])

#display the size of the array
print("\nThe length of chordArray is:", len(chordArray))
#add content at the end of the array, using append
chordArray.append(70)
print("\nAfter adding an element to chordArray, its length is:", len(chordArray))

#loop through the array and print content
print("\nLooping through chordArray, and printing its content:")
for midiNote in chordArray:
  print(midiNote)

#remove an element from the end, using pop
print("\nThe Array.pop function removes and returns an arrays last element:",
  chordArray.pop())

#another way to loop through an array, using its index
print("\nLooping through chordArray, and printing the index and content:")
for i in range(len(chordArray)):
  print("At index " + str(i) + ":", chordArray[i])
