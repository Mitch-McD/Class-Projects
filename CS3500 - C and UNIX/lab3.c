#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int exit = 0; // 0 if successful, 1 if error is thrown
    int strCnt = 0; // 0 if input is empty, 1 if full
 
    char *input; 
    char *output = "output.dat"; 
    double value = 50;

    // check for no values or too many
    if (argc <= 1 || argc >= 7)
	exit = 1;

    int i;
    for (i=1;i<argc;i++) {
	char *buf = argv[i];
	if (buf[0] == '-') {
	    // determine the type of flag
	    switch(buf[1]) {
		case 'o': // output
                    if (argv[i+1]) { 
		        output = argv[i+1];
			i++;
		    }
		    else
			exit = 1;
		    break;
		case 'q': // value
		    if (argv[i+1]) { 
		        value = atof(argv[i+1]);
			i++;
		    }
		    else
			exit = 1;
		    break;
		default:
		    exit = 1;
		    break;
	    }
        }
	else {
            // if input empty, assign input
	    if (strCnt == 0) {
	        input = argv[i];
		strCnt = 1;
            }
	    else
		exit = 1;
	}
    }
    // if input is empty after assign (because if(!input) didn't work for me)
    if (strCnt == 0)
	exit = 1;
    // if any error was thrown
    if (exit == 1)
	printf("Error\n");
    else {
	printf("Input: %s\n",input);
	printf("Output: %s\n",output);
	printf("Value: %.2f\n",value);
    }

    return 0;
}
