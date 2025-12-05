CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC = src/wc.c
OBJ = $(SRC:.c=.o)
TEST = test/test_mini.c

all: test_mini

test_mini: $(OBJ) $(TEST)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f src/*.o test_mini