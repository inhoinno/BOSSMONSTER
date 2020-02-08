#include <iostream>
using namespace std;
int main(){
    int N;

    cin >>N;
    if(N<100000){
        for(int i=0; i< N; i++){
            cout<<(N-i)<<"\n";
        }
    }



    return 0;
}
