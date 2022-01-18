PROCESS_NAME = ../tp5-frontend
IDIR = ./include
ODIR = ./obj
SRCDIR = ./src
LEXDIR = ./analyzers
BISDIR= ./analyzers
LIBS = -lfl -ly -lcommons
CC=gcc
CFLAGS=-I$(IDIR) -I$(COMMONS_IDIR) -L$(COMMONS_LDIR) -g -Wall

DEPS = $(wildcard $(IDIR)/*.h)
COMMONS_DEPS = $(wildcard $(COMMONS_IDIR)/*.h)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(ODIR)/%.o,$(SRC))

$(PROCESS_NAME): $(OBJ) $(ODIR)/parser.o $(ODIR)/scanner.o 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS) $(COMMONS_DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(SRCDIR)/scanner.c: $(LEXDIR)/scanner.l
	flex -o$@ $^

$(SRCDIR)/parser.c: $(BISDIR)/parser.y
	bison --defines=$(IDIR)/parser.h -o$@ $^

$(ODIR):
	mkdir -p $(ODIR)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SRCDIR)/scanner.c $(PROCESS_NAME) yyout.txt