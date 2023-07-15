#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    
    int m = 8;

    int *array = (int *) calloc(m,sizeof(int));
    
    FILE *fp;
    
    if((fp = fopen(argv[1],"r")) == NULL) {
    	printf("File didn't open.");
	free(array);
	return 1;
    }
    

    int i = 0;
    while(!feof(fp)) {    
        int val; 
        fscanf(fp, "%d\n",&val);
        
        array[i++] = val;
	if (m == val) {
            m *= 2;
            array = realloc(array,m*sizeof(int));
	    printf("Memory has been reallocated (size = %d) ...\n", m);
        }
    }
    int j = 0;
    while (j < i)
    	printf("%d ", array[j++]);
    free(array); 
    fclose(fp); 
    printf("\n");    
    return 0;
}
