OUTDIR  = build/
OUT     = $(OUTDIR)opdracht3b
CXX     = g++
CFLAGS  = -Wall -std=c++14
LDFLAGS = -ljack
ODIR    = $(OUTDIR)obj
SDIR    = src
INC     = -Iinc

all: $(OUT)

_OBJS = main.o
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
