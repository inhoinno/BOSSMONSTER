#include <iostream>
#include <cstdio>
using namespace std;
int D_Stair(int n){
    int d[101];
    d[0] = 0;
    d[1] = 9;
    if(d[n]>0) return d[n];
    else{
        d[n] = D_Stair(n-1)*2 -1;
        return d[n];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }
};
int main (){
    int N;
    scanf_s("%d", &N);
    if(N>=1 && N<=100) printf("%d", D_Stair(N));
    else printf("오류\n");
    return 0;
}