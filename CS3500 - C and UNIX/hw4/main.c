#include <stdio.h>
#include "file.h"


int main(int argc, char **argv) {

if (argc != 3) {
    printf("Wrong number of arguments (should be 3)\n");
    return 1;
}

FILE *fr = NULL;
if ((fr = fopen(argv[1], "rb")) == NULL) {
    printf("Could not open read file.");
    return 1;
}

FILE *fw = NULL;
if ((fw = fopen(argv[2], "wb")) == NULL) {
    printf("Could not open write file.");
    return 1;
}
int fileType = getType(fr);
if (fileType == 2) {
    fclose(fr);
    fileType = 2;
    if ((fr = fopen(argv[1], "r")) == NULL) {
	printf("Could not open read text file.");
	return 1;
    }
    skipType(fr);
}

int *heightWidth = getSize(fr);

int size = heightWidth[0] * heightWidth[1];
size = (fileType == 6 ? size*3 : size);

skipIntensity(fr);

char *array = getData(fr, fileType, size);

writeToFile(fw, fileType, array, size, heightWidth);

free(array);

fclose(fr);
fclose(fw);

return 0;
}
