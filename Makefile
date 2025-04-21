CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/process.c src/resource.c src/timeout.c
OUT = resource_allocator

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
