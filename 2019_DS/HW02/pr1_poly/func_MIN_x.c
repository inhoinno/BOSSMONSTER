/*32152332 송인호 32152332@dankook.ac.kr*/
#include "poly.h"

double func_MIN_x(struct List * L, int min, int max){
	double i = 0;
	double x = 0;
	double unit = _UNIT;
	int j = 0;
	double min_f = calc(L, min); //최소값 초기화 후 
	for (i = min + 0.1; i < max; i += unit){ //0.1씩 증가
		double res = calc(L, i); //값을 계산
		if (min_f > res) {  //최소값보다 더 작은 값이 존재한다면 
			min_f = res; // 그값을 최소값으로 치환
				x = i;
		};
	}
	return x;
}