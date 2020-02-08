#include "sort.h"
void Sort_Selection(int * data, int size){
	int i, j;
	for (i = 0; i<size - 1; i++){
		for (j = i; j<size; j++){
			if (data[i] > data[j])
				swap(&data[i], &data[j]);
		}

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
	int move = 0; //false
	for (i = 1; i<size; i++){
		key = data[i];
		j = i;
		if (data[j - 1] > key)
			move = 1; //true
		else move = 0; //false
		while (move){4
			data[j] = data[j - 1];
			j = j - 1;
			if (j > 0 && key < data[j - 1])
				move = 1; //true
			else move = 0; //false
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
	return t;

}
int boot_Sorting(){
	int button;
	double t;
	//int j = 0;
	while (1){
		printf("1번 선택정렬 5번, 2번 버블정렬 5번, 3번. 삽입정렬 0번. 종료\n");
		scanf("%d", &button);
		//srand(time(NULL));
		//button = rand() % 3 + 1;
		if (button == 0) return 0;
		int i = 0;
		while (i < 10){
			i++;
			//	scanf("%d", &button);
			if (button == 0){
				printf("Sorting 프로그램 종료..\n");
				return 0;
			}
			// printf("데이터 설정중...\n");
			// 새로운 크기10000~10000000의 배열 
			int data_size = Set_Size();
			int * deck = Set_Data(data_size);
			printf("%d 개의 배열 생성!\n", data_size);
			switch (button)
			{
			case 0:
				free(deck);
				printf("Sorting프로그램 종료...");
				return 0;
			case 1://selection
				t = Sorting_Clock(Sort_Selection, deck, data_size);
				//	printf("선택정렬의 경과시간: %f sec\n", t);
				file_addline("selection", data_size, t);
				printf("%d번 실행중.. 시간 %f ..\n", i, t);
				break;

			case 2://bubble
				t = Sorting_Clock(Sort_Bubble, deck, data_size);
				//	printf("버블정렬의 경과시간: %f sec\n", t);
				file_addline("bubble", data_size, t);
				printf("%d번 실행중.. 시간 %f ..\n", i, t);
				break;

			case 3://insertion
				t = Sorting_Clock(Sort_Insertion, deck, data_size);
				//	printf("삽입정렬의 경과시간: %f sec\n", t);
				file_addline("insertion", data_size, t);
				printf("%d번 실행중.. 시간 %f ..\n", i, t);
				break;
			default:
				printf("Unidentified number, please check options...");
			}
			if (Is_Sorted_Acending_order(deck, data_size)){ printf(" completely sorted!\n"); }
			else{ printf("Not completely Sorted.....\n"); }
		}//while
		//	j++;
	}//while
	printf("Sorting Program Terminated....\n");
	return 0;
}
int Is_Sorted_Acending_order(int* data, int n){
	int i = 0;
	for (i = 0; i<n - 4; i += 4){ //Acendind_Order
		if (!(data[i] <= data[i + 1] && data[i + 1] <= data[i + 2] && data[i + 2] <= data[i + 3]))
			return 0;
	}
	if (i != n - 1)
		for (; i<n - 1; i++)
			if (!(data[i] <= data[i + 1]))
				return 0;
	return 1;
}