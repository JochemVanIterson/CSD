# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

# the build target executable:
SOURCE = src/main.cpp
TARGETFOLDER = build/
TARGET = opdracht1

all: $(TARGETFOLDER)$(TARGET)

$(TARGETFOLDER)$(TARGET): $(SOURCE)
	mkdir -p $(TARGETFOLDER)
	$(CC) $(CFLAGS) -o $(TARGETFOLDER)$(TARGET) $(SOURCE)

clean:
	$(RM) -R $(TARGETFOLDER)
