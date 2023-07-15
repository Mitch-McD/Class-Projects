#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"
#include "decode.h"

Storage * convertFromBit(FILE *fp) {
    
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    rewind(fp);
    int byteSize = fileSize*8;
    int *bytes = readKBits(fp, fileSize);
     
    while (byteSize%17 != 0)
	byteSize--;
    
    int bitCount = 0;
    int j;
    int i = 0;
    static Storage data[N*N];
    
    i = 0;
    while (bitCount < byteSize) {
	int sign = bytes[bitCount++];
	int total = 0;
	for (j = 5; j >= 0; j--) {
	    int x = bytes[bitCount++];
	    total += x*pow(2,j);
	}
	data[i].occurrence = total+1;
	
	total = 0;
	for (j = 9; j >= 0; j--) {
	    int x = bytes[bitCount++];
	    total += x*pow(2,j);
	}
	if (sign == 1)
	    total *= -1;
	data[i].val = total;
	i++;
    }
    free(bytes);
    return data;
}

int * readKBits(FILE *fp, int fileSize) {
    unsigned char buffer[fileSize];
    int *bytes = (int*) malloc(fileSize*8*sizeof(int));
    fread(buffer, 1, fileSize, fp);
    int byte[8];
    int count = 0;
    int i,j;
    for (i = 0; i < fileSize; i++) {
        int val = (int)buffer[i];
        for (j = 7; j >= 0; j--) {
	    int x = val % 2;
	    val = val / 2;
	    byte[j] = x;
	}
	for(j = 0; j < 8; j++) {
	    bytes[count] = byte[j];
	    count++;
	}
    }
    return bytes;
}


void printData(Storage *data) {
    int i = 0;
    int j;
    int count = 0;
    while (data[i].val != 0 || data[i].occurrence != 0) {
	for(j = 0; j < data[i].occurrence; j++) {
	    printf("%d ", data[i].val);
	    count++;
	}
	i++;
    }
    printf("\n\n");
}

Matrix convertToMatrix(Storage *data) {
    int i = 0;
    int j;
    int x = 0;
    int element[N*N];
    Matrix C2;
    while (data[i].val != 0 || data[i].occurrence != 0) {
        for(j = 0; j < data[i].occurrence; j++)
	    element[x++] = data[i].val; 
	i++;
    }


    int limit = N*2-1; // total number of diagonal rows
    int diag; // for loop counters
    int count = 0, direction = 0, startPos = 0;
    for (diag = 0; diag < limit; diag++) {
        if (diag < N) {
            j = diag;
            for (i = 0; i <= diag; i++) {
                if (direction == 0)
		    C2.element[j--][i] = element[count++];
		else
		    C2.element[i][j--] = element[count++];
	    }
	} else { // when diagonal row length is decreasing
            j = N-1;
            startPos++;
            for (i = startPos; i < N; i++)
        	if (direction == 0)
                    C2.element[j--][i] = element[count++];
                else
                    C2.element[i][j--] = element[count++];
	}
        // if up, change to down, vice versa
        if(direction == 0)
            direction = 1;
        else
            direction = 0;
    }



    return C2;
}


