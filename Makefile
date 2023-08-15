CC = gcc
CFLAGS = -g -Wall
EXE = expressiontrees
HEADERS = types.h tree.h stack.h
CODE = tree.c stack.c expressiontrees.c

OBJECTS = $(CODE:.c=.o)

expressiontrees: $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE)

clean:
	rm -f *.o *.exe *.out