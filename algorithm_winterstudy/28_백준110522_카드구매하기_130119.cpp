#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int D_maxcal(int n, int* F){
	int D[100];
    
	if (D[n] > 0) return D[n];
	else{
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= i; j++){
				D[i] = (D_maxcla(i) > D_maxcal(i - j) + F[j]) ? D[i] : D[i - j] + F[j];
			}
		}
		return D[n];
	}
	return 0;


}
int main(){
	int N=0;
	int i = 0;
	scanf("%d", &N);
	int F[N] = {-1};
	for ( i = 0; i<N; i++)
		scanf("%d", &F[i]);
        
	printf("%d", D_maxcal(N, F));

	return 0;
}