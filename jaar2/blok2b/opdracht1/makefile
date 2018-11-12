$(shell mkdir -p build/)

all: build/opdracht1

build/opdracht1: build/main.o build/instrument.o build/dbgPrint.o
	g++ -o build/opdracht1 build/main.o build/instrument.o build/dbgPrint.o

build/main.o: src/main.cpp
	g++ -c -o build/main.o src/main.cpp

build/instrument.o: src/instrument.cpp src/instrument.h
	g++ -c -o build/instrument.o src/instrument.cpp

build/dbgPrint.o: src/dbgPrint/dbgPrint.cpp src/dbgPrint/dbgPrint.h
	g++ -c -o build/dbgPrint.o src/dbgPrint/dbgPrint.cpp

clean:
	rm -R build/
