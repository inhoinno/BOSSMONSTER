#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int N;
	int count = 0;

	scanf_s("%d", &N);

	while (N != 1){
		if (N % 3 == 0){//3으로 나누어 떨어지면
			N /= 3;
			count++;
		}
		else if (N % 2 == 0){
			N /= 2;
			count++;
		}
		else { N -= 1; count++; }
	}
	printf("%d \t", count);



	return 0;
}
