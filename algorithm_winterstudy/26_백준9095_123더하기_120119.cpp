#include <iostream>
#include <cstdio>
using namespace std;
int DynamicGo(int n){
	int d[11];
	d[0] = 1;
	d[1] = 1;
	d[2] = d[0] + d[1];
	if (d[n]>0) return d[n];
	else{
		d[n] = DynamicGo(n - 1) + DynamicGo(n - 2) + DynamicGo(n - 3);
		return d[n];
	}
	//d[2] = d[1] + d[0]
	//d[3] = d[2] + d[1] + d[0]
}
int main(){
	int N;
	scanf_s("%d", &N);
	if (N < 11){
		printf("%d", DynamicGo(N));
	}
	else printf("0");
	return 0;
}