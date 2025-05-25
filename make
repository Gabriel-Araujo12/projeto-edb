XEC = restaurante

CC = gcc

CFLAGS = -Wall -g

OBJ = main.o restaurante.o

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

main.o: main.c restaurante.h
    $(CC) $(CFLAGS) -c main.c

restaurante.o: restaurante.c restaurante.h
    $(CC) $(CFLAGS) -c restaurante.c

clean:
    rm -f *.o $(EXEC)