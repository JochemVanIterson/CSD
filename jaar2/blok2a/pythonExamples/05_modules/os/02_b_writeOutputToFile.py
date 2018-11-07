import os.path

"""
from: https://docs.python.org/3/tutorial/inputoutput.html
  "It is good practice to use the "with" keyword when dealing with file objects.
  The advantage is that the file is properly closed after its suite finishes,
  even if an exception is raised at some point."
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

#open the file "output.txt"
with open("output.txt", "a") as outputFile:
  outputFile.write("Let's add a line to this file!")

#file is closed automatically
print("The 'output.txt' file is closed automatically when the suite " +
      "is finished, using the 'with' keyword, outputfile.closed = ",
      outputFile.closed)
