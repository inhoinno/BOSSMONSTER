#include <iostream>
#include <cstdio>
using namespace std;

int main (){
    /*포도주 시식 -> n번째 잔은 연속 j번 마신 잔
    0번 연속일때 = n번째 잔(A[n])은 안마신거임
                > n-1번째 잔 까지 알아서 마시면 댐
                > D[n-1]

    1번 연속일때 = n번째 잔을 마시고 전 잔(n-1)은 안마신거임
                > n-1번째는 안마시고(0번 연속) A[n]마심
                >D[n-1][0] +A[n]

    2번 연속일때 = n-1 ,n 둘다 마신거임
                > n-3까지 알아서 잘 마시고, n-2안마시고 n-1마시고 n 마심ㅇㅋ?
                D[n-3] + A[n-1] + A[n]
    */
   d[1] = a[1];
   d[2] = a[1] + a[2];
   for(int i=3 i<=n; i++){
       d[i] =d[i-1];
       if(d[i]<d[i-2] + a[i]){
           d[i] =d[i-2] +a[i];
       }
       if(d[i] < d[i-3]+a[i]+a[i-1]){
           d[i] = d[i-3] +a[i]+a[i-1];
       }
   }



}