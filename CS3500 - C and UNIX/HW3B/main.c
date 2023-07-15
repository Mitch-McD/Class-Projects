#include <stdio.h>
#include "encode.h"
#include "util.h"



int main(int argc, char **argv) {
    Matrix M = {{10,4,2,5,1,0,0,0,
                 3,9,1,2,1,0,0,0,
                 -7,-5,1,-2,-1,0,0,0,
                 -3,-5,0,-1,0, 0,0,0,
                 -2,1,0, 0,0,0,0,0,
                 0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0}};

    FILE *fp; 

    if ((fp = fopen(argv[1], "wb")) == NULL) {
	printf("This file could not be opened.");
	return 1;
    }

    int *data = reorder(M);
    Storage *occOfVal =  countConsecutive(data);
    convertToBits(occOfVal, fp); 
    
    fclose(fp);

    return 0;
}

