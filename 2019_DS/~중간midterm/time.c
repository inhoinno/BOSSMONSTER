/*
1002일 수요일ㅇ 까지 제출
1. 3가지 정렬
2. 행렬의 곱. 자료구조의 변형
3. 시간 분석
4. 오브젝트파일 생성
5. 토의

데이터의 크기는 10000에서 1000000
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
#define Max_Size 1000000;
#define Min_Size 100000;
#define _CRT_SECURE_NO_WARNINGS

void file_addline(char* str, int, double);
void swap(int*, int*);
void Sort_Selection(int *, int); //선택
void Sort_Bubble(int *, int); //버블
void Sort_Insertion(int *, int); //삽입
double Sorting_Clock(void *(func)(int*, int), int*, int); //측정시간 재는 함수
int boot_Sorting();
bool Is_Sorted(int *, int);
int random();
int* Set_Data(int);
int Set_Size();
///정렬



int main(){
	boot_Sorting();
	printf("프로그램 종료..\n");

	return 0;
}
void file_addline(char* str, int size, double sec){
	FILE *fp = fopen("result.txt", "a");
	if (fp == NULL){
		fp = fopen("result.txt", "w");
		if (fp == NULL) {
			printf("FILE OPEN ERROR!\n");
			return;
		}
	}
	fprintf(fp, "%s %d %lf \n", str, size, sec);
	return;
}

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
void Sort_Selection(int * data, int size){
	int i, j, min;
	for (i = 0; i<size - 1; i++){
		min = i;
		for (j = i; j<size; j++){
			if (data[i] > data[j])
				min = j;
		}
		if (min == i)
			continue;
		swap(&data[i], &data[min]);
	}
	return;
}
void Sort_Bubble(int * data, int size){
	int i, j, exch;
	for (i = size - 1; i>0; i--){
		exch = 0;
		for (j = 0; j<i; j++){
			if (data[j] > data[j + 1]){
				exch++;
				swap(&data[j], &data[j + 1]);
			}
		}
		if (exch == 0)
			break;
	}
	return;
}
void Sort_Insertion(int * data, int size){
	// 원소 k(=A[i], 0<i<n)를 
	// 부분배열 A[0: i-1]에 오름차순으로 삽입
	// for(i=1; i<n; i = i+1){ 
	//     k = A[i];
	// j = i;
	// if(A[j-1]>k) then move = true
	// else move = false;
	// while(move) do {
	//     a[j] = a[j-1]
	//     j = j-1
	//     if(j>0 && a[j-1] > k ) then move = true;
	//     else move= false
	// }
	// a[j] =k;
	// }
	int i, j, key;
	bool move = false;
	for (i = 1; i<size; i++){
		key = data[i];
		j = i;
		if (data[j - 1] > key)
			move = true;
		else move = false;
		while (move){
			data[j] = data[j - 1];
			j = j - 1;
			if (j > 0 && key < data[j - 1])
				move = true;
			else move = false;
		}
		data[j] = key;
	}
	return;

}
double Sorting_Clock(void *(func)(int *, int), int* data, int d_size){
	clock_t start, end;
	start = clock();
	func(data, d_size);
	end = clock();
	double t = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f초 ",t);
	return t;

}

bool Is_Sorted_Acending_order(int* data, int n){
	int i = 0;
	for (i = 0; i<n - 4; i += 4){ //Acendind_Order
		if (!(data[i] <= data[i + 1] && data[i + 1] <= data[i + 2] && data[i + 2] <= data[i + 3]))
			return false;
	}
	if (i != n - 1)
		for (; i<n - 1; i++)
			if (!(data[i] <= data[i + 1]))
				return false;
	return true;
}
int random(){
	srand(time(NULL));
	return (rand() % 10 + 1);
}
int* Set_Data(int n){//데이터 초기화그리고 변경
	int* d = (int*)malloc(n*sizeof(int));
	int i;
	for (i = 0; i<n - 4; i += 4){
		d[i] = random(); d[i + 1] = random(); d[i + 2] = random(); d[i + 3] = random();
	}
	if (i != n - 1)
		for (; i < n; i++)
			d[i] = random();
	return d;
}
int Set_Size(){ ///10000 ~ 1000000
	srand(time(NULL));
	int t = rand() % Max_Size + Min_Size;
	return t; //10000~1000000무작위 크기
}
int boot_Sorting(){
	int button;
	double t;
	printf("아무키나 누르면 시작해요. 0번은 종료. \n $ ");
	scanf("%d", &button);
	while (button != 0){
		// 새로운 크기10000~10000000의 배열 
		int data_size = Set_Size();
		int * deck = Set_Data(data_size);
		int * dk = (int*)malloc(10 * sizeof(int));
		printf("data size = %d\n", data_size);
		//      Sorting_Clock(Sort_Selection())
		//      Sorting_Clock(Sort_Bubble())
		//      Sorting_Clock(Sort_Insertion())
		printf("Sort program 실행!\n");
		printf("1번 : 선택정렬 실행, 2번 : 버블정렬 실행, 3번 삽입정렬 실행, 4번 데이터 사이즈 재설정. 0번. 프로그램 종료\n");
		while (scanf("%d", &button)){
			memcpy(dk, deck, sizeof(data_size*sizeof(int)));
			switch (button)
			{//sort 후 shuffle
			case 0:
				free(deck); free(dk);
				return 0;

			case 1://selection
				t = Sorting_Clock(Sort_Selection, dk, data_size);
				printf("의 경과시간: %f sec", t);
				file_addline("selection", data_size, t);
				break;

			case 2://bubble
				t = Sorting_Clock(Sort_Bubble, dk, data_size);
				printf("의 경과시간: %f sec", t);
				file_addline("bubble", data_size, t);
				break;

			case 3://insertion
				t = Sorting_Clock(Sort_Insertion, dk, data_size);
				printf("의 경과시간: %f sec", t);
				file_addline("bubble", data_size, t);
				break;

			case 4:
				break;

			default:
				printf("Unidentified number, please check options...");
				continue;
			}

		}
	}
	return 0;


}