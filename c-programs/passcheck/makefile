#
# Makefile for passcheck.c
#
# Compiler: GCC
#

PROGRAM_NAME = passcheck
CC = gcc

.PHONY: clean

$(PROGRAM_NAME): $(PROGRAM_NAME).c $(PROGRAM_NAME).h
	$(CC) $(PROGRAM_NAME).c -o $(PROGRAM_NAME)
	
clean:
	rm -f $(PROGRAM_NAME)