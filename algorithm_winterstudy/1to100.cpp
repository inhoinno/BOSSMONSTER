#include <iostream>
using namespace std;
define MAX_INTEGER =100;
//O(N^2) = n(n-1) /2 
int main(){
    int result =0;
    int t=0;
    int n = MAX_INTEGER;
    string sb = "";
    for(int i =0; i<n; i++ ){
        result += i+1;
        for(int j =0; j< i+1; j++)
            cout << j+1 << "+ ";
        cout << '\t' <<" ===> "<< result<< endl; 
    }
    return 0;


}