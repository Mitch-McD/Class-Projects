#include <stdio.h>
#define N 8

typedef struct _Matrix {
    int element[N][N];
} Matrix;



int main() {
    Matrix M = {{10,4,2,5,1,0,0,0,
                 3,9,1,2,1,0,0,0,
                 -7,-5,1,-2,-1,0,0,0,
                 -3,-5,0,-1,0, 0,0,0,
                 -2,1,0, 0,0,0,0,0,
                 0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0,
                 0,0,0,0,0,0,0,0}};
    int limit = N*2-1; // total number of diagonal rows
    int i,j,diag; // for loop counters
    int count = 0, direction = 0, startPos = 0;
    int data[N*N];

    for (diag = 0; diag < limit; diag++) {
        if (diag < N) { // when diagonal row length is increasing
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

    // print out data
    for (i = 0; i < N*N; i++)
       printf("%d ", data[i]);
    printf("\n\n");

    //consecutive number counter
    count = 1;
    for (i = 0; i < N*N-1; i++) {
        if (data[i] == data[i+1]) {
            count++;
        } else {
            printf("%d %d\n", data[i], count);
            count = 1;
        }
    }
    printf("%d %d\n", data[N*N-1], count);

    return 0;
}
