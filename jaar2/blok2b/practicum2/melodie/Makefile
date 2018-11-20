OUTDIR = build/
OUT    = $(OUTDIR)practicum2_melodie
CXX    = g++
CFLAGS = -Wall -std=c++14
ODIR   = $(OUTDIR)obj
SDIR   = src
INC    =

all: mkdir $(OUT)

_OBJS = main.o melody.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CFLAGS) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(OUT) $^

.PHONY: clean

mkdir:
	$(shell mkdir -p $(OUTDIR))
	$(shell mkdir -p $(ODIR))

clean:
	rm -f -R $(OUTDIR)
