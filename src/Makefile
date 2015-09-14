IDIR =../inc
CC=g++
CFLAGS=-I$(IDIR) -std=c++0x

ODIR=obj

# Unused
LDIR =../lib

# Unused
LIBS=-lm

_DEPS = TFile.hpp TString.hpp algorithms/TIterator.hpp containers/TContainer.hpp containers/TDynamicArray.hpp #containers/TLinkedList.hpp
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

# needed?
# containers/TDynamicArray.o containers/TLinkedList.o
_OBJ = TFile.o TString.o main.o
# _LIBOBJ = TFile.o TString.o containers/TDynamicArray.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))
# LIBOBJ = $(patsubst %, $(ODIR)/%, $(_LIBOBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS) $(LIBS)

# lib: $(LIBOBJ)
# 	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS) $(LIBS)
# 	$(CC) -shared -Wl, -soname, libtoonie.so.1 -o libtoonie.so.1.0 $(ODIR)/*.o
# 	ln -sf libtoonie.so.1.0 libtoonie.so
# 	ln -sf libtoonie.so.1.0 libtoonie.so.1

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
