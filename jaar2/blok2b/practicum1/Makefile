CC = g++
CFLAGS = -std=c++11

$(shell mkdir -p build/)

all: build/practicum1

build/practicum1: build/main.o build/Car.o
	$(CC) $(CFLAGS) -o build/practicum1 build/main.o build/Car.o

build/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -o build/main.o src/main.cpp

build/Car.o: src/Car.cpp src/Car.h
	$(CC) $(CFLAGS) -c -o build/Car.o src/Car.cpp

clean:
	rm -R build/
