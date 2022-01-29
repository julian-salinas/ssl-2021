IDIR=include
SRCDIR=src
LEXDIR=analyzers
BISONDIR=analyzers
LIBS=-lfl
CC=gcc
CFLAGS=-Wall -I $(IDIR) -g

all: flex bison
	$(CC) $(SRCDIR)/*.c -I $(IDIR) $(CFLAGS) $(LIBS) -o tp5

flex:
	flex --outfile=$(SRCDIR)/scanner.c --header-file=$(IDIR)/scanner.h $(LEXDIR)/scanner.l

bison:
	bison --defines=$(IDIR)/parser.h -o $(SRCDIR)/parser.c $(BISONDIR)/parser.y 
