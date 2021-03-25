CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=multiplicite

all: $(EXEC)

multiplicite: multiplicite.o main.o
    $(CC) -o $@ $^ $(LDFLAGS)

multiplicite.o: multi.c
    $(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c multi.h
    $(CC) -o $@ -c $< $(CFLAGS)

clean:
    rm -rf *.o

mrproper: clean
    rm -rf $(EXEC)
