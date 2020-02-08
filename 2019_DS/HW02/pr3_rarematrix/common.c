
#include <stdlib.h>
#include <time.h>
#include "common.h"
int random(int K){
    int d =rand() % K +1; //? data범위 어쩔거야? 
    return d;
}
int ** array(int row, int col){
    int ** arr = (int **)malloc(sizeof(int*)*row);
    for(i =0; i< row; i++){
        *(arr+i) = (int *)malloc(sizeof(int)*col);
    }
    arr[row][col] = {0,};
    return arr;
}
int get_row(int** M){
    int i=sizeof(M) / sizeof(&M[0]);
    return i;
}
int get_col(int** M){
    int i= sizeof(&M[0]) / sizeof(int); 
    return i;
}
