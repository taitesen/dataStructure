# Directories
LIB_DIR = lib
BUILD_DIR = build
SRC_DIR = src

# FLAGS
CC = gcc
FLAGS = -Wall -Werror -Wextra -Wshadow -Og -g

OBJECT = $(BUILD_DIR)/main.o \
		 $(BUILD_DIR)/ll.o

LIB_SOURCE = $(LIB_DIR)/ll.c
MAIN_SOURCE = $(SRC_DIR)/main.c

TARGET = bin

all: $(TARGET)

# Build
## Binding
$(TARGET): $(OBJECT)
	$(CC) $(OBJECT) -o $@

## Compiling
$(BUILD_DIR)/ll.o: $(LIB_SOURCE)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $^ -o $@

## Compiling
$(BUILD_DIR)/main.o: $(MAIN_SOURCE)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $^ -o $@

# Cleaning
clean:
	@rm -rf build bin

.PHONY: all clean


