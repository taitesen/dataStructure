SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = build

OBJ = $(OBJ_DIR)/main.o \
	  $(OBJ_DIR)/lib.o
SRC = $(SRC_DIR)/main.c
LIB = $(LIB_DIR)/lib.c

CC = gcc
FLAG = -Wall -Wshadow -Wextra -Werror -Og -g

TARGET = bin

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

$(OBJ_DIR)/main.o: $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(OBJ_DIR)/lib.o: $(LIB)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

clean:
	@rm -rf $(TARGET) $(OBJ_DIR)

.PHONY: all clean
