#include <stdio.h>
#include "util.h"
#include "decode.h" 

int main(int argc, char **argv) {

    FILE *fp;
    if ((fp = fopen(argv[1], "rb")) == NULL) {
	printf("Unable to open file.");
	return 1;
    }
    
    Storage *data = convertFromBit(fp);
    printData(data);
    Matrix C2 = convertToMatrix(data);
    PrintMatrix(C2);

    fclose(fp);

    return 0;
}
