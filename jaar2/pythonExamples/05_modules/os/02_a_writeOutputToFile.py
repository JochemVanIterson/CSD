import os.path

"""

"""

#check if the file output.txt already exists
if os.path.isfile("output.txt"):
  #the file already exists, check if the user wants to alter it
  alterFile = input( "The file output.txt already exists." +
            "Should we alter this file? y/n - ")
  if alterFile == "n":
    #user does not want to alter the file -> exit program
    print("Okay, then we shutting this program down!")
    exit()

#open the file "output.txt" (will be created if it does not exist)
#mode options:
# r - reading
# w - writing
# a - appending
# r+ - reading and writing
outputFile = open("output.txt", "a")

#write a string to file
outputFile.write("Let's add a line to this file!")

#don't forget to close the file
outputFile.close()
