//매트릭스
// 희소행렬 크기를 입력받아서
// 10퍼센트 비율로 희소행렬 만들기
// 10퍼 real data, 90퍼 0
/*32152332 소프트웨어학과 송인호 32152332@dankook.ac.kr*/
#include "sparse.h"
#include "common.h"

int ** my_sparse_matrix(int row ,int col){ //sparse matrix생성자
	srand(time(NULL));
	int i;
	int checker = 0;
	int sum = 0;
	printf("%d x %d 사이즈의 희소행렬 생성 , = %.2f\n\n", row, col, (double)row*col);
	int ** sparse = array(row, col);
	//THEN, RANDOM(ROW) , RANDOM(COL) 에 데이터를 넣어줌 RATIO만큼
	int r = RATIO;
	r = row*col / r;
	for (i = 0; i<r; i++){
		int tmp1 = random(row); //random row
		int tmp2 = random(col); //random col
		int k = random(11) +1; //random data 0~10
		if (sparse[tmp1][tmp2] == 0){
			//중복 수행
			sparse[tmp1][tmp2] = k;
			checker ++;
			sum += k;
		}
		
	}
	printf("희소행렬 %dx%d = %d 에 %d 개의 data set.... \n\tsum :%d\n", row,col,row*col, checker,sum);
	return sparse;
}
int valid_value(int** M, int row, int col){
	int count = 0;
	int i = 0; int j = 0;
	for (i=0; i < row; i++)
		for (j=0; j < col; j++)
			if (M[i][j] != 0)
				count++;
	return count;
}
MATRIX* AD_sparse_matrix(int** M, int rw, int cl){
	/*
	sparse matrix
	sparse matrix의 크기 = d
	matrix의 원소들의 갯수 = d/10
	*/
	int i;
	int j;
	int count = valid_value(M, rw, cl);
//	int size = rw *cl / r; //this is S[R]
//	size = size + 1;

	struct MATRIX *sm =(MATRIX *)malloc(sizeof(MATRIX)*(count+1));
	
	sm[0].row = rw;
	sm[0].col = cl;
	sm[0].val = count;
	//now r는 희소행렬의 원소들의 갯수가 됨.(10퍼센트)
	//plus one for attributes of matrix : row&col length, quantity of data 
	int k = 1;
	for (i = 0; i<rw; i++){
		for (j = 0; j < cl; j++){
			if (M[i][j] != 0){
				sm[k].row = i; sm[k].col = j; sm[k].val = M[i][j]; k++;
			}
		}
		
	}
	return sm;
}
double add_all_sparse(MATRIX * sm){// sm은 sparse matrix들을 새로운 자료구조로 변형 한 것
	
	int r = sm[0].val ; //총 개인지
	printf("sm[0]val = %d\n\n", r);
	int i;
	double sum = 0;
	
	for (i = 1; i<=r; i++){
//		if (sm[i].val > 10 && sm[i].val < 0){
//			printf("%d %d %d", sm[i].row, sm[i].col, i);
//		}
		sum += sm[i].val; 
	}
	return sum;
}

//행렬 trans -> sparse
//행렬 끼리의 곱 -> 
void main(){
	int r; int c;
	printf("희소행렬 크기 입력 \nm:");
	scanf("%d", &r);
	printf("n:");
	scanf("%d", &c);
	int ** arr = my_sparse_matrix(r,c);
	MATRIX* sm = AD_sparse_matrix(arr, r, c);
	double sum = add_all_sparse(sm);
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			printf(" %d", arr[i][j]);
		}printf("\n");
	}
	for (i = 0; i <=sm[0].val; i++)
		printf(" %d : %d %d %d\n",i, sm[i].row, sm[i].col, sm[i].val);
	printf("희소행렬의 모든 원소들의 합 : %f\n", sum);
}