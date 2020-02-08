//top-down
#include <iostream>
#include <cstdio>
using namespace std;
int DynamicThinkingPlease(int n){
	int d[10000]; //memoization
	if (n == 1) return 0;
	if (d[n]>0) return d[n]; // d[n]이 음수면 최소값판단이 아직인거고,
	// d[n]이 양수, 즉 판단이 끝난넘이면 바로 return합니다, ; memoization메모이제이션!
	d[n] = DynamicThinkingPlease(n - 1) + 1;
	if (n % 2 == 0){
		d[n] = d[n] > DynamicThinkingPlease(n / 2) + 1 ? DynamicThinkingPlease(n / 2) + 1 : d[n];
	}
	if (n % 3 == 0){
		
		d[n] = d[n] > DynamicThinkingPlease(n / 3) + 1 ? DynamicThinkingPlease(n / 3) + 1 : d[n];
	}
	return d[n];
};
int main(){
	int n;
	scanf_s("%d", &n);
	printf("%d\n", DynamicThinkingPlease(n));
	return 0;
}
