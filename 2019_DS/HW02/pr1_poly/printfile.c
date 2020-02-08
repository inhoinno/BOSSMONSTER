//x값, 계산값을 파일에 저장
#include "poly.h"
void printfile(double x, double result){
	FILE *fp = fopen("poly_result.txt", "a");
	if (fp == NULL){
		printf("File open error!\n");
		return;
	}
	fprintf(fp, "%f %f\n", x, result);
	return;
}