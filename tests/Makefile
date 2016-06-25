## CONFIG
TITLE = tests
CC    = gcc
OUT   = $(TITLE)

## FILES
SRC  = main.c
OBJ  = $(SRC:.c=.o)

## DEPENDENCIES
PWD     = $(shell pwd)

## FLAGS
CFLAGS   = -c -g -Wall -Wno-address -Wno-unused-result -O3

## RULES
all: $(OUT)

debug: clean clearscr all run

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $*.c -o $@

clean:
	rm -f -v $(OBJ) $(OUT)

clearscr:
	clear

run:
	./$(OUT)
