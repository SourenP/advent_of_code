CC = gcc
CFLAGS = -Wall -std=c99 -g
objects = day_1 day_2
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o $(objects)
