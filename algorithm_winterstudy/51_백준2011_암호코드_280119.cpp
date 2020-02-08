#include<String>
using namespace std;

class Solution {
    public:
    int SolvingEncryption(string s){
        int mod = 1000000;
        //M으로 나올수 있는 해석 몇개?
        int D[5001] ; // i번째 문자까지 해석했을 때, 나올 수 있는 해석의 가짓 수 
        int n = s.size();
        s = " " + s;
        d[0] = 1;
        for (int i=1; i<=n; i++) {
            int x = s[i] - '0';
            if (1 <= x && x <= 9) {
                d[i] += d[i-1];
                d[i] %= mod;
            }
            if (i==1) {
                continue;
            } 
            if (s[i-1] == '0') {
                continue;
            } //05 같은 암호
            x = (s[i-1]-'0')*10 + (s[i]-'0');
            if (10 <= x && x <= 26) {
                d[i] += d[i-2];
                d[i] %= mod;
            }
        }
        return d[n];

    }
}