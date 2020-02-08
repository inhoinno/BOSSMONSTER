/*32152332 송인호*/
/*func 를 0으로 만드는 x값의 범위를 찾아내야함. */
/*
찾는법.

CAL(X) 와 CAL(X+1)의 부호가 다르다면,
X와 X+1사이에 있다는것

*/

#include "poly.h"
bool meet_zero(double x1, double x2){
	if (x1 < 0 && x2 >0) //증가하면서 0을 만남
		return true;
	else if (x1>0 && x2<0) // 감소하는 구간에서 0을 만남
		return true;
	else
		return false;

}
void realloc_mat(int * sptr, double*** arr){
	int newsize = *(sptr)+3;
	double** temp = (double**)malloc(sizeof(double *) * newsize);
	int i;
	for (i = 0; i< *(sptr); i++){
		temp[i] = (*arr)[i];
	}//copy complete
	//주소값을 다시 temp로 줌
	free(*arr);
	*arr = &temp[0];
	*sptr = *sptr + 3;
	return;
}
double** func_zero_find_x(struct List * L){
	int min = MIN_X;
	int max = MAX_X;
	int size = 10;
	double unit = _UNIT;
	int i;
	double ** rx = (double**)malloc(sizeof(double*)*size);//range of x
	// 0의 값을 가지는 범위를 담을 이차원 배열. 구조체를 사용한 자료구조를 써도 무방하다.
	for (i = 0; i < size; i++){
		rx[i] = (double*)malloc(sizeof(double) * 2);
	}
	//10개값을 저장할수있는 10x2인 배열
	double k = 0;
	int count = 0;
	//범위를 잡기 애매하다
	//1 범위를 넓게 잡는다면 퍼포먼스가 올라가지만 hole이 생길수있고
	//2 범위가 좁다면 시간이 오래걸리게 됨.
	for (k = min; k < max; k += unit){
		double x1 = calc(L,k);
		double x2 = calc(L, k + unit);
		if (meet_zero(x1, x2)){
			printf("check\n");
			if (count >= size - 1){//rx가 full되면, count 0123456789 , 추가로 배열할당
				printf("alloc check\n");
				realloc_mat(&size, &rx[0]);
			}
			rx[count][0] = k;
			rx[count][1] = k+unit;
			count++;
		}//만족하면 0을 지나는것

	}
	rx[count] = NULL;
	return rx;

}