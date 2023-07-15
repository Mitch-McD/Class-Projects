CC = gcc
DEPS = a2.h a3_d.h a3_e.h a5_file.h util.h
LIBS = -lm -std=c99 

all: a2.o a3_d.o a3_e.o a5_file.o decode.o encode.o util.o
	$(CC) $(LIBS) a2.o a3_e.o a5_file.o encode.o util.o -o encode
	$(CC) $(LIBS) a2.o a3_d.o a5_file.o decode.o util.o -o decode
	rm *.o

a2.o:
	$(CC) $(LIBS) a2.c -c

a3_d.o:
	$(CC) a3_d.c -c

a3_e.o:
	$(CC) a3_e.c -c

a5_file.o:
	$(CC) a5_file.c -c

decode.o:
	$(CC) $(LIBS) decode.c -c

encode.o:
	$(CC) $(LIBS) encode.c -c

util.o:
	$(CC) util.c -c
