SRCDIR = src
LIBDIR = lib
OBJDIR = build

CC = gcc
FLAG = -Wall -Wextra -Wshadow -Werror -Og -g

OBJ = $(OBJDIR)/stack.o \
	  $(OBJDIR)/main.o

TARGET = bin
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

$(OBJDIR)/%.o: $(LIBDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@


clean:
	@rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
