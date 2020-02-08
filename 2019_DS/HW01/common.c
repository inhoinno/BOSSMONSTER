#include "common.h"
void file_addline(char* str, long long size, double sec){
	FILE *fp = fopen("resultnew1002.txt", "a");
	if (fp == NULL){
		fp = fopen("resultnew1002txt", "w");
		if (fp == NULL) {
			printf("FILE OPEN ERROR!\n");
			return;
		}
	}
	//if (size < 0){
	//	char* arr = "over_MAX_INTEGER!";
	//	fprintf(fp, "%s %s %lf \n", str, arr, sec);
	//}
	//else{
		fprintf(fp, " %s %ld %f \n", str, size, sec);
	//}
	fclose(fp);
	return;
}
void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
int* Set_Data(int n){//데이터 초기화그리고 변경 (수정바람)
	// 	어떻게 10만개의 배열을 초기화 할것인가? //n배열을 1. 생성 2. 값을 초기화
	int* d = (int*)malloc(n*sizeof(int));
	int i;
	srand(time(NULL));
	for (i = 0; i <= n - 4; i += 4){//if n=5 i=4<5-4 !
		d[i] = random(); d[i + 1] = random(); d[i + 2] = random(); d[i + 3] = random();
	}
	if (i != n - 1)// i=4 n-1 =4
		for (; i < n; i++)
			d[i] = random();
	return d;
}
int random(){
	return (rand() % 10 + 1);
}
int Set_Size(){ ///10000 ~ 1000000
	//srand((unsigned)time(NULL)); 보통 1초 안에 모두 처리가 되기 때문에 여기 서주는게 아니라고한다.
	//rand_Max는 0x7fff , 32767 까지임. 근데 우리의 데이터 최대크기는 1000000백만이다.
	//따라서 추가 연산을 해서 진정한 무작위 크기n(10000<n<1000000)을 만드는 과정
	int t = rand() * rand() % Max_Size; //int_max  = 2,147,438,647 , rand_max^2 = 1,073,676,289
	t += Min_Size;
	//t %= 6000;// t += 400000;
	return t; //10000~1000000무작위 크기
}
int** create_Array(int m, int l){ // A mXl 행렬 만들기
	
	int** a = (int**)malloc(sizeof(int*) * m); //행갯수(m))a[m]
	a[0] = (int*)malloc(sizeof(int)* m*l); // 전체a[m][l]
	int i;
	for (i = 1; i< m; i++){
		a[i] = a[i - 1] + l;
	}
	return a; // a[rand][l]
}
void Set_Arr_Data(int **d, int row, int col){
	int i, j;
	srand(time(NULL));
	for (i = 0; i< row; i++){
		d[i] = Set_Data(col);
	}
	return;
}
void Ctrl_Size(int* m, int* n, int* l){ /// m n l
	double t1 = (double)(*m)*(*l);
	double t2 = (double)(*l)*(*n);
	int pivot = 2;
	int M = Max_Size;
	while (t1> M || t2>M){
		if (t1 > M){
			*m /= pivot +1;
			*l /= pivot +1;
			t1 = (double)(*m)*(*l);
		}
		else if (t2 > M){
			*n /= pivot +1;
			t2 = (double)(*l)*(*n);
		}
	}
	return;
}