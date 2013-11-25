#####makefile for kproc######

COMPI=gcc

kproc:
	$(COMPI) $(CFLAG) -o kproc kproc.c

