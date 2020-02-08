#include <iostream>
using namespace std;
int 2times2is44times4is16(int N){
    int d[100001];
    for(int i=1; i<=N; i++){
        d[i] = i;
        for(int j=1; j*j<= i ; j++){
            if(d[i]> d[i-j*j]+1){
                d[i] = d[i-j*j]+1;
            }
        }
    }
    return 0;
}