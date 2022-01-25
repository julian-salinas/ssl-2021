IDIR=include
SRCDIR=src
LEXDIR=analyzers
BISONDIR=analyzers
LIBS=-lfl
CC=gcc
CFLAGS=-Wall -I$(IDIR) -g

all: flex bison
	mv scanner.c src/
	mv parser.c src/
	mv parser.h include/
	mv scanner.h include/
	$(CC) $(SRCDIR)/*.c -I $(IDIR) $(CFLAGS) $(LIBS)

flex:
	flex $(LEXDIR)/scanner.l

bison:
	bison -d $(BISONDIR)/parser.y
