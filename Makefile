CC = gcc
CFLAGS = -Iinclude -lpthread  # Add -Iinclude to specify where to find header files

SRC = src/main.c src/process.c src/resource.c
OUT = allocator  # Output executable name

# Build rule
all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

# Clean up compiled files
clean:
	rm -f $(OUT)
