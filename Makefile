CC = gcc
CFLAGS = -g -Wall
EXE = project4
HEADERS = types.h tree.h stack.h
CODE = tree.c stack.c project4.c

OBJECTS = $(CODE:.c=.o)

project4: $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXE)

clean:
	rm -f *.o *.exe *.out