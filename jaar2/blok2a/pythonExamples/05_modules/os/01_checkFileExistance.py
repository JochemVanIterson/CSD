import os.path

"""
You can check if a file exists by using the os module:
os.path.isfile([_filename_])
This function returns True / False, according to the existence of the file.
"""

print("The file foo.txt does not exist, os.path.isfile('foo.txt') returns: ",
      os.path.isfile("foo.txt"))

print("Let's create the file foo.txt, by using the 'open' function")
open('foo.txt', "a").close()

print("Now let's check again if the file foo.txt exists: ",
      os.path.isfile("foo.txt"))

removeFile = input("We are removing the file 'foo.txt', are you sure? y/n - ")
if removeFile == 'y':
  os.remove("foo.txt")
