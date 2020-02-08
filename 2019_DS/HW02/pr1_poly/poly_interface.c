/*32152332 송인호 32152332@dankook.ac.kr*/
#include "poly.h"
#include <time.h>

void boot_poly(){
	double i = 0;
	double unit = _UNIT;
	int j;
	int min = MIN_X;
	int max = MAX_X;
	clock_t start, end;

	// 2000개
	struct List * Lf = myList();
	addTerm_Last(Lf, 6.7, 4);
	addTerm_Last(Lf, 3.2, 3);
	addTerm_Last(Lf, -1, 2);
	addTerm_Last(Lf, 1, 1);
	addTerm_Last(Lf, -2, 0);
	showList(Lf);
	//-10부터 10 까지 범위
	printf("\n<<<  범위 [ %d : x : %d ] , 단위unit = %f  >>>\n\n", min, max, unit);
	printf("------\n$ # [ 1. calc함수 실행 ( N = %.1f) ] \n",(max - min)/unit);
	start = clock();
	for (i = min; i<max; i += unit){
		double d = calc(Lf, i);
		//printfile(i, d);
		//printf("\n f(%.2f) = %.3f", i, d);
	}
	end = clock();
	i = (double)(end - start) / CLOCKS_PER_SEC;
	printf("$\t실행 완료. \n$ # calc 함수 실행시간 : %f ( [-10 : x + i : 10 ] , i = %f ) \n\n\n\n", i , unit);
	/*어떻게 0이 되는 범위를 구할 수 있을까? */
	
	printf("------\n$ # [ 2. f(x) = 0 가 되는 x값의 범위 구하기 (약 %.1f회 반복)\n$",(max - min) / unit);
	start = clock();
	double ** xresult = func_zero_find_x(Lf);
	end = clock();
	i = (double)(end - start) / CLOCKS_PER_SEC;
	printf("$ # find_zero 함수의 경과시간 %f . ( N = %.1f)\n$\n$", i, (max - min) / unit);
	for (j = 0; xresult[j] != NULL; j++){
		printf("\n$  0이 되는 x값의 %d번째 범위\t[ %f <= X <= %f ]\n$",j+1, xresult[j][0], xresult[j][1]); // x의범위
	}

	/*어떻게 주어진 범위에서 최소값을 구할 수 있을까?*/
	printf("\n\n\n------\n$ # [ 3. 주어진 범위 내 최소값 찾기 ]\n");
	start = clock();
	double min_f = func_MIN_x(Lf, min, max); 
	end = clock();
	i = (double)(end - start) / CLOCKS_PER_SEC;
	printf("$ 최소값 func min함수 실행 경과 시간 : %f , ( N = %.1f)  ", i, (max - min) / unit);
	printf("\n$ 범위 내 최소값\n -> \t[%d : x :%f 일때  최소값 f(x): %f : %d ]\n", min, min_f , calc(Lf,min_f), max);
	return;

}
/*32152332 송인호 32152332@dankook.ac.kr*/

int main(){
	boot_poly();
	return 0;
}