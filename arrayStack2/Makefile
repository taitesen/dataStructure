SRCDIR = src
LIBDIR = lib
OBJDIR = build

CC = gcc
FLAG = -Wall -Wextra -Wshadow -Werror -Og -g

OBJ = $(OBJDIR)/main.o \
	  $(OBJDIR)/util.o \
	  $(OBJDIR)/init.o \
	  $(OBJDIR)/stack.o

SRC = $(SRCDIR)/main.c
UTIL = $(LIBDIR)/util.c
STACK = $(LIBDIR)/stack.c
INI = $(LIBDIR)/init.c

TARGET = bin

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(OBJDIR)/main.o: $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(OBJDIR)/util.o: $(UTIL)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(OBJDIR)/stack.o: $(STACK)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(OBJDIR)/init.o: $(INI)
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

clean:
	@rm -rf build bin

.PHONY: all clean
