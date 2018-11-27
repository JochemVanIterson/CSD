OUTDIR = build/
OUT    = $(OUTDIR)opdracht2
CXX    = g++
CFLAGS = -Wall -std=c++14
ODIR   = $(OUTDIR)obj
SDIR   = src
INC    = -Iinc

all: $(OUT)

_OBJS = main.o instrument.o subinstruments/inst_guitar.o subinstruments/inst_piano.o subinstruments/inst_strings.o subinstruments/inst_winds.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
	$(CXX) $(CFLAGS) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(OUT) $^

.PHONY: clean

$(BUILD_DIR)%/:
	 mkdir -p $@

clean:
	rm -f -R $(OUTDIR)
