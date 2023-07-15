CC = gcc
DEPS = file.h
LIBS = -lm 

all: main.o file.o
	$(CC) $(LIBS) main.o -o hw5 file.c
	rm main.o
	rm file.o

main.o:
	$(CC) main.c -c

file.o:
	$(CC) file.c -c

