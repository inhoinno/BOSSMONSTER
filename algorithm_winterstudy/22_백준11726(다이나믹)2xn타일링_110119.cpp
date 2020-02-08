#include <iostream>
#include <cstdio>
using namespace std;
//top-down
int MyDynamic(int n){
    int T[1000]; //memoization
    T[0] =1;
    T[1] =1;
    if(T[n]>0) return T[n];
    else {
        T[n] = MyDynamic(n-2) + MyDynamic(n-1);
        return T[n];
    }
};
int main(){
    int N;
    scanf("%d", &N);
    printf("%d" ,MyDynamic(N));
    return 0;
}