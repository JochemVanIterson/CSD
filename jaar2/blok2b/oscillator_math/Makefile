OUTDIR  = build/
OUT     = $(OUTDIR)oscillator_math
CXX     = g++
CFLAGS  = -I/usr/local/include -Wall -std=c++14
LDFLAGS = -ljack
ODIR    = $(OUTDIR)obj
SDIR    = src
INC     = -Iinc

all: $(OUT)

_OBJS = main.o oscillator/oscillator.o oscillator/generator.o jack/jack_module.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
	$(CXX) $(CFLAGS) -c $(INC) -o $@ $<

$(OUT): $(OBJS)
	$(CXX) $(CFLAGS) -o $(OUT) $^ $(LDFLAGS)

.PHONY: clean

$(BUILD_DIR)%/:
	 mkdir -p $@

clean:
	rm -f -R $(OUTDIR)
