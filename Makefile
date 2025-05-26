CC = gcc
CFLAGS = -Wall -Wextra -g
EXEC = restaurante
OBJS = main.o restaurante.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

main.o: main.c restaurante.h
	$(CC) $(CFLAGS) -c main.c

restaurante.o: restaurante.c restaurante.h
	$(CC) $(CFLAGS) -c restaurante.c

clean:
	rm -f $(EXEC) $(OBJS)
