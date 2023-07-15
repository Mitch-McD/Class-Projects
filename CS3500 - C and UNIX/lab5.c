#include <stdio.h>
#include <stdlib.h>
#include<math.h>


// -lm is required for use of power function

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Incorrect amount of variables entered.\n");
        return 1;
    }
    int val = atoi(argv[1]);
    printf("Value: %d\n", val);

    int k = pow(2,atoi(argv[2]));
    val = (val | k);

    int i;
    int valByte[8];
    for (i=0; i<8; i++) {
	valByte[i] = val%2;
	val = val/2;
    }

    for (i=8; i>0; i--) {
	printf("%d", valByte[i-1]);
    }
    printf("\n");
    return 0;
}
