#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char buf[80];
    int numRead = 0;
    while (numRead<2) {
	int num;
	fgets(buf, 80, stdin);
	sscanf(buf, "%d ", &num);
	printf(num);
    }

    return 0;
}
