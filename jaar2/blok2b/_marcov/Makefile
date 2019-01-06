OUTDIR  = build/
OUT     = $(OUTDIR)marcov
CXX     = g++
CFLAGS  := -Wall -std=c++17
LDFLAGS = -ljack
ODIR    = $(OUTDIR)obj
SDIR    = src
INC     = -Iinc

all: $(OUT)

_OBJS = \
	main.o \
	jack/jack_module.o \
	tools/tools.o \
	melody/melody_provider.o \
	melody/marcov.o \
	melody/midiplayer.o \
	melody/sequencer.o \
	midi/midiProvider.o \
	midi/libmidifile.a \
	threadTimer/threadTimer.o \
	oscillators/voice.o \
	oscillators/oscillator.o \
	oscillators/waveforms/sine.o \
	oscillators/waveforms/square.o \
	oscillators/waveforms/saw.o \
	oscillators/waveforms/triangle.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	@if [ ! -d $(@D) ]; then mkdir -p $(@D); echo "create folder $(@D)"; fi
	$(CXX) $(CFLAGS) -c $(INC) -o $@ $< $(CFLAGS)

$(ODIR)/%.a: $(SDIR)/%.a
	@if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
	cp $< $@

$(OUT): $(OBJS)
	@echo "Linking files";
	@$(CXX) $(LDFLAGS) -o $(OUT) $^

.PHONY: clean

$(BUILD_DIR)%/:
	 mkdir -p $@

clean:
	rm -f -R $(OUTDIR)
