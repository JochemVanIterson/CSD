OUTDIR  = build/
OUT     = $(OUTDIR)marcov
CXX     = g++
CFLAGS  = -Wall -std=c++14
LDFLAGS = -ljack
ODIR    = $(OUTDIR)obj
SDIR    = src
INC     = -Iinc

all: $(OUT)

_OBJS = \
	main.o \
	jack/jack_module.o \
	melody/melody.o \
	melody/marcov.o \
	midi/libmidifile.a
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
	$(CXX) $(CFLAGS) -c $(INC) -o $@ $< $(CFLAGS)

$(ODIR)/%.a: $(SDIR)/%.a
	if [ ! -d $(@D) ]; then mkdir -p $(@D); fi
	cp $< $@

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(OUT) $^

.PHONY: clean

$(BUILD_DIR)%/:
	 mkdir -p $@

clean:
	rm -f -R $(OUTDIR)
