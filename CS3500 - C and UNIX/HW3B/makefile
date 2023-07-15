CC = gcc
DEPS = util.h encode.h decode.h
LIBS = -lm

all: main.o main2.o encode.o util.o decode.o
	$(CC) $(LIBS)  main.o -o encode encode.o util.o
	$(CC) $(LIBS)  main2.o -o decode decode.o util.o
	rm encode.o
	rm main.o
	rm util.o
	rm main2.o
	rm decode.o

main.o:
	$(CC) main.c -c

encode.o:
	$(CC) encode.c -c

util.o:
	$(CC) util.c -c

main2.o:
	$(CC) main2.c -c

decode.o:
	$(CC) decode.c -c
