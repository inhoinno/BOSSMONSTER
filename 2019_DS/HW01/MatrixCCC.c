#include <time.h>
#include <stdio.h>
double Multiple_Clock(void *func(int**, int**, int, int, int), int** A, int** B, int m, int l, int n);
void boot_Matrix_Multiplication();
int** Multiple_Mat(int ** A, int ** B, int m, int l, int n);
int** ADV_Multiple_Mat(int **, int **, int m, int l, int n);
int** T_Mat(int **, int, int);

double Multiple_Clock(void *func(int**, int**, int**, int, int, int), int** A, int** B,int** C, int m, int l, int n){
	clock_t start, end;
	start = clock();
	C = func(A, B, C, m, l, n);
	end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
void boot_Matrix_Multiplication(){
	double t;
	int i = 0;
	while (i < 5){ //5번 결과에 대해 파일에 출력
		int m, l, n;
		srand((unsigned)time(NULL));
		m = Set_Size(); n = Set_Size(); l = Set_Size();
		Ctrl_Size(&m, &n, &l);
		printf("m = %d, l = %d, n = %d\n ", m, l, n);
		int** A = create_Array(m, l);
		int** B = create_Array(l, n);
		printf("AB생성");
		Set_Arr_Data(A, m, l);
		Set_Arr_Data(B, l, n);
		int** C = create_Array(m, n);
		Set_Arr_Data(C, m, n);
		printf("DATA설정 완료\n곱셈 실행!...\n");
		t = Multiple_Clock(Multiple_Mat, A, B, C,m, l, n); //1. multiclock 설정한다? 2. 그냥 clockt한다.
		printf("A %d X  %d / B %d X %d 에 대한 행렬 곱 연산\n %f초...\n", m, l, l, n, t);
		//	file_addMat(m,l,n,t);
		char str[30];
		sprintf(str, "%d %d %d", m, l, n);
		file_addline(str, m*l*n, t);
		B = T_Mat(B, l, n); //자료구조 변형해서 다시 곱
		t = Multiple_Clock(ADV_Multiple_Mat, A, B,C, m, l, n);
		printf("A %d X  %d / TB %d X %d 에 대한 행렬 곱 연산\n %f초...\n", m, l, l, n, t);
		sprintf(str, "TB %d %d %d", m, l, n);
		file_addline(str, m*l*n, t);

		i++;
		free(C);
	}
	return;
}
int** Multiple_Mat(int ** A, int ** B, int** C, int m, int l, int n){
	//int** data=create_A_Mat(m,n);
	// i j sum k data[m][n]
	int i, j, k, sum;
	for (i = 0; i< m; i++){
		for (j = 0; j<n; j++){
			sum = 0;
			for (k = 0; k<l; k++){
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}
	return;
}
int** T_Mat(int** B , int l ,int n){ //B[l][n]
	//행 열 열 행
	// B = {2 ,0}, {3, 0} , {0,3} B[j][i]
	// B' = {2,3,0},{0,0,3} B[i][j]
	int i, j;
	int ** TB = create_Array(n, l);
	for (i = 0; i < n; i++){
		for (j = 0; j < l; j++){
			TB[i][j] = B[j][i];
		}
	}
	return TB;
}
int** ADV_Multiple_Mat(int ** A, int **B, int** C , int m, int l, int n){
	int i, j, k, sum;
	for (i = 0; i< m; i++){
		for (j = 0; j<n; j++){
			sum = 0;
			for (k = 0; k<l; k++){
				sum += A[i][k] * B[j][k]; //?
			}
			C[i][j] = sum;
		}
	}
	return;

}