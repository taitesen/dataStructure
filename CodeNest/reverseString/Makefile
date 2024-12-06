SRCDIR = src
LIBDIR = lib
OBJDIR = build

CC = gcc
FLAG = -Wall -Wextra -Wshadow -Werror -Og -g

OBJ = $(OBJDIR)/main.o \
	  $(OBJDIR)/stack.o

SRC = $(SRCDIR)/main.c
LIB = $(LIBDIR)/stack.c

TARGET = bin

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(OBJDIR)/main.o: $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(OBJDIR)/stack.o: $(LIB)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

clean:
	@rm -rf build bin

.PHONY: all clean
