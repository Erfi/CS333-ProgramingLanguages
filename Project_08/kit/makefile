CC = gcc
CFLAGS = -pthread -std=c99 -Wall
DEPS = ppmIO.h
OBJ = ppmIO.o par_colorize.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

colorize: $(OBJ)
	gcc $(CFLAGS) -o $@ $^