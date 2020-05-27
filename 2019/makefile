CC = gcc
CFLAGS = -Wall -std=c99
objects = day_1
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
