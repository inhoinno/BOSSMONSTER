/*

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

*/
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i< 2 * N - 1; i++){
		if (i<N){
			for (int j = 0; j<N; j++){
				if (j <= i)
					printf("*");
				else
					printf(" ");

			}
			for (int j = 0; j<N; j++){
				if (N - j - 1 <= i)
					printf("*");
				else
					printf(" ");
			}
		}
		else{
			for (int j = 0; j < N; j++){

				if (j < 2 * N - 1-i) printf("*");
				else printf(" ");
			}
			for (int j = 0; j<N; j++){
				if (j <= i - N) printf(" ");
				else printf("*");
			}
		}
		puts("");
	}
	system("pause");
	return 0;
}