#include <stdio.h>
#include <math.h>
#include "encode.h"
#include "util.h"

#define N 8

int * reorder(Matrix M) {
    int limit = N*2-1; // total number of diagonal rows
    int i,j,diag; // for loop counters
    int count = 0, direction = 0, startPos = 0;
    static int data[N*N];
    for (diag = 0; diag < limit; diag++) {
        if (diag < N) {
            j = diag;
            for (i = 0; i <= diag; i++)
                data[count++] = (direction == 0 ? M.element[j--][i] : M.element[i][j--]);
        } else { // when diagonal row length is decreasing
            j = N-1;
            startPos++;
            for (i = startPos; i < N; i++)
                data[count++] = (direction == 0 ? M.element[j--][i] : M.element[i][j--]);
        }
        // if up, change to down, vice versa
        if(direction == 0)
            direction = 1;
        else
            direction = 0;
    }
    return data;
}

Storage * countConsecutive(int *data) {
    //consecutive number counter
    static Storage occOfVal[N*N];
    int count = 1;
    int i;
    int x = 0;
    for (i = 0; i < N*N-1; i++) {
        if (data[i] == data[i+1]) {
            count++;
        } else {
            occOfVal[x].val = data[i];
            occOfVal[x++].occurrence = count;
            count = 1;
        }
    }
    occOfVal[x].val = data[N*N-1];
    occOfVal[x].occurrence = count;
    return occOfVal;
}

void convertToBits(Storage *occOfVal, FILE *fp) {
    int i = 0;
    int size = 0;

    while (occOfVal[i].val != 0 || occOfVal[i].occurrence != 0) {
        size++;
        i++;
    }
    writeKBits(occOfVal, size, fp);
}

void writeKBits(Storage *occOfVal, int dataSize, FILE *fp) {
    int i = 0;
    while ((17*dataSize+i)%8 != 0) {
        i++;
    }
    int byteSize = dataSize*17 + i;
    int count = 0;
    int bytes[byteSize];
    i = 0;
    while (i < dataSize) {
        int val = occOfVal[i].val;
        int occurrence = occOfVal[i].occurrence - 1;
        i++;
        int sign;
        int sixbit[6];
        int tenbit[10];
        if (val >= 0)
            sign = 0;
        else {
            sign = 1;
            val = val * (-1);
        }
        bytes[count++] = sign;
        int j;
        for (j = 5; j >= 0; j--) {
            int x = occurrence % 2;
            occurrence = occurrence / 2;
            sixbit[j] = x;
        }
        for (j = 0; j < 6; j++)
            bytes[count++] = sixbit[j];
        for (j = 9; j >= 0; j--) {
            int x = val % 2;
            val = val / 2;
            tenbit[j] = x;
        }
        for (j = 0; j < 10; j++)
            bytes[count++] = tenbit[j];
    }
    while (count < byteSize)
	bytes[count++] = 0;
    count = 0;
    unsigned char buffer[byteSize/8];
    int j;
    for (i = 0; i < byteSize/8; i++) {
	int total = 0;
	for(j = 7; j>=0; j--) { 
	    int x = bytes[count];
	    total += x*pow(2, j);
	    count++;
	}
	buffer[i] = total;
    }
    fwrite(buffer, 1, byteSize/8, fp);
}
