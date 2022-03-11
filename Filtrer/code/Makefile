###
## Makefile skeleton
## INFO0947: Projet 1
##
###

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=

# Files
EXEC=filtrer
MODULES=main.c filtrer.c
OBJECTS=main.o filtrer.o

## Rules

all: $(EXEC)

filtrer: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

filtrer.o: filtrer.c
	$(CC) -c filtrer.c -o filtrer.o $(CFLAGS)


clean:
	rm -f *.o $(EXEC) *~

