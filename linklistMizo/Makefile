# Directories
LIB_DIR = lib
SRC_DIR = src
OBJ_DIR = build

# Flags
CC = gcc
FLAG = -Wall -Werror -Wshadow -Wextra -Og -g

OBJECTS = $(OBJ_DIR)/main.o \
		  $(OBJ_DIR)/ll.o

MAIN_SOURCES = $(SRC_DIR)/main.c
LIB_SOURCES = $(LIB_DIR)/ll.c

TARGET = bin

todolist: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJ_DIR)/main.o: $(MAIN_SOURCES)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $^ -o $@

$(OBJ_DIR)/ll.o: $(LIB_SOURCES)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $^ -o $@

clean:
	@rm -rf build bin

.PHONY: clean all
