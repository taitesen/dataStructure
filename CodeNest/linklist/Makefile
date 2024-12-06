# Directories
LIB_DIR = lib
OBJ_DIR = build
SRC_DIR = src

# FLAGS
CC = gcc
FLAGS = -Wall -Werror -Wextra -Wshadow -Og -g

OBJECT = $(OBJ_DIR)/main.o \
		 $(OBJ_DIR)/ll.o

LIB_SOURCE = $(LIB_DIR)/ll.c
MAIN_SOURCE = $(SRC_DIR)/main.c

TARGET = bin

all: $(TARGET)

# Build
## Binding
$(TARGET): $(OBJECT)
	$(CC) $(OBJECT) -o $@

## Compiling
$(OBJ_DIR)/ll.o: $(LIB_SOURCE)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $^ -o $@

## Compiling
$(OBJ_DIR)/main.o: $(MAIN_SOURCE)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $^ -o $@

# Cleaning
clean:
	@rm -rf build bin

.PHONY: all clean


