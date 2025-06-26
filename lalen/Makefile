# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -O2
LDFLAGS :=

# Paths
SRC     := src/lalen.c
LIB     := lib/lib.c
INCLUDE := -Iinclude

# Output
BIN     := build/lalen
TESTBIN := build/test-lalen

# Grouped source files
SRCS    := $(SRC) $(LIB)

# Build rules
all: $(BIN)

$(BIN): $(SRCS) include/lib.h | build
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -o $(BIN)

build:
	mkdir -p build

clean:
	rm -rf build

install: $(BIN)
	sudo install -Dm755 $(BIN) /usr/local/bin/lalen

uninstall:
	sudo rm -f /usr/local/bin/lalen

test: $(BIN)
	./$(BIN)

.PHONY: all clean install uninstall test build
