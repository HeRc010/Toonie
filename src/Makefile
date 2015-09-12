IDIR =../inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++0x

ODIR=obj

# Unused
LDIR =../lib

# Unused
LIBS=-lm

_DEPS = TFile.hpp TString.hpp containers/TContainer.hpp containers/TDynamicArray.hpp
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o TFile.o TString.o containers/TDynamicArray.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
