#include <stdlib.h>
#include <stdio.h>
int main (){
    int length = 4;
    int * array = (int *) malloc(length*sizeof(int));
//  int array[4]; 라고 쓰면, array는 배열이라서 바꿀 수 없음. 크기 못늘림.
    array[0] =1;
    array[1] =2;
    array[2] =3; 

    int * tmp =(int *)malloc(8*sizeof(int));
    int i;
    for(int i=0; i<4; i++)
        tmp[i] = array[i];

    array =tmp;
    //if array[4] 라고 쓰면 여기에서 array에 빨간 밑줄이 생깁니다.

    array[4] =4;
    array[5] = 5;
    printf("%d", *(array+5) );
    return 0;
}