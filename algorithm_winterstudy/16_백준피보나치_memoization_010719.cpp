#include <iostream>
#include <cstdio>
int fibonacci(int n){
    int memo[100];
    if(n<=1) return n;
    else{
        if(memo[n]>0) return memo[n];
        else {
            memo[n]= fibonacci(n-1) + fibonacci(n-2);
            return memo[n];
        }
    }
}
int main(){
    int N;
    scanf_S("%d". &N);
    printf("\n%d", fibonacci(N));



    return 0;
}