using namespace std;
class Solution{
    public:
    int NandK(){
        long long d[201][201];
        long long mod = 1000000000;
        d[0][0] = 1LL;
        for (int i=1; i<=k; i++) {
            for (int j=0; j<=n; j++) {
                for (int l=0; l<=j; l++) {
                    d[i][j] += d[i-1][j-l];
                    d[i][j] %= mod;
                }
            }
        }

    }

}s