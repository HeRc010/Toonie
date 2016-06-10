IDIR=inc
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = containers/linked_list/linked_list.h containers/linked_list/linked_list_tests.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = test.o containers/linked_list/linked_list.o containers/linked_list/linked_list_tests.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ exec
