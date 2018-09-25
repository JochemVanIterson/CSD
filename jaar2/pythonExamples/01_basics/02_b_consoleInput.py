"""
Another M&T version of "Hello World", this time with console input

------ HANDS-ON TIPS ------
1. Add another textual sound to the 3 current options, update the communication
   to the user,  the input check and the sound sellection accordingly.
"""

#The built-in function input() enables you to read a line from the console
print("Please enter your name and hit enter.")
userName = input("Your name = ")


#Let the user choose a sound.
#The while loop enables us to re-ask the question if the answer is incorrect.
correctSelection = False
while correctSelection != True:
  #Ask user to choice a sound and inform about the available options.
  print("\nHi", userName + ", which of the sounds below do you prefer?")
  print("1 - a soft whoosh")
  print("2 - a loud BANG")
  print("3 - a crazy Doinngggg")

  #retrieve input
  selection = input("Sound number = " )

  #transform selected number to an number.
  #NOTE: we should check if 'selection' is a number, however this is
  #out of scope for this example
  selectionInt = int(selection)

  #check if the input equals to 1, 2, 3
  if selectionInt is 1 or selectionInt is 2 or selectionInt is 3:
    #correct input -> stop while loop
    correctSelection = True
  else:
    #incorrect input -> inform user
    print("Sorry, you entered an incorrect number, please try again.")

print("Okay, here it comes:")


#Let's fetch the correct sound string.
#Using an if ... elif ... elif ... sequence to select corresponding sound
#according to the user input.
#Python does not have a switch or case statement, which a lot of other languages
#do have. To get around this fact, you can use dictionary mapping.
if selectionInt == 1:
  sound = ".......... w w w w W W hhhhooooosssshhhhhh....."
elif selectionInt == 2:
  sound = "******** B-A-N-G *********"
elif selectionInt == 3:
  sound = "---D oooO iiiIIII nnnggGGG ggggG gggGGgGggggg------ "

#print the sound
print(sound)
