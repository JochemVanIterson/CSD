"""
This script contains a simple example of working with lists.
"""

#Let's create a list to hold a C major chord in midi-notes.
aChord = [60, 64, 67]
print("The list aChord:", aChord)

#access content of the list at a specific index
print("\nAt index 1, aChord contains:", aChord[1])

#alter content at a specific index
aChord[1] = 63
print("\nAltered content at index 1, this now contains:", aChord[1])

#display the size of the list
print("\nThe length of aChord is:", len(aChord))
#add content at the end of the list aChord, using append
aChord.append(70)
print("\nAfter adding an element to aChord, its length is:", len(aChord))

#loop through the list and print content
print("\nLooping through aChord, and printing its content:")
for midiNote in aChord:
  print(midiNote)

#remove an element from the end of the list aChord, using pop
print("\You can use the pop function to remove and return a list last element:",
  aChord.pop())

#another way to loop through a list, using its index
print("\nLooping through aChord, and printing the index and content:")
for i in range(len(aChord)):
  print("At index " + str(i) + ":", aChord[i])
