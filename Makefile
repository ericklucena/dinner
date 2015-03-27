CC=gcc
CPPFLAGS=
CFLAGS= -std=c99 -Wall -pedantic -Iinclude -g
LDFLAGS= -lpthread

all: src/*
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o bin/dine

clean: 
	rm bin/*
