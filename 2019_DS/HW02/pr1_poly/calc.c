/*
주어진 x값으로 다항식의 각 항을 계산하는 프로그램
*/
#include "poly.h"

double calc(struct List * L, double x){ // x에 대해서 계산 하는 calc
	struct Term * inode = malloc(sizeof(struct Term));
	inode = L->head; // now tnode is head
	double cal_result = 0;
	while (inode->next != NULL){ //O(n) , n 은 리스트의 크기
		int expon = inode->cha; // 차수, 
		double term_sum = 0;
		term_sum = pow(x, expon); //차수 계산, pow 는 math.h안에 정의
		term_sum = term_sum * inode->gge; // 계수 계산
		cal_result += term_sum;  //각 항 계산 결과를 result에 저장
		inode = inode->next;    //iterate
	}
	//마지막항 계산해줘
	double tmp = pow(x, inode->cha);
	tmp *= inode->gge;
	cal_result += tmp;

	return cal_result;
}