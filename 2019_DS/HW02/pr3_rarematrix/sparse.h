/*32152332 소프트웨어학과 송인호 32152332@dankook.ac.kr*/
#include <stdio.h>
#include "common.h"

#ifndef _SPARSE_
#define _SPARSE_
#define RATIO 10;
typedef struct MATRIX {
	int row;
	int col;
	int val;
} MATRIX;
int ** my_sparse_matrix(int ,int);
MATRIX* AD_sparse_matrix(int**, int, int);
double add_all_sparse(MATRIX*);
int valid_value(int**, int, int);
#endif
