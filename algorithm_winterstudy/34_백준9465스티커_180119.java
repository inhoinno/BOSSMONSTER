class Solution {
    public int Cuticker(int[][] StK, int n){
        int D[1000][3]
        
        D[0][0] = 0; D[0][1] = Stk[0][1]; D[0][2] = Stk[0][0];
        for(int i=1; i<n; i++){
            
            D[i][0] = max(D[i-1][0],D[i-1][1],D[i-1][2]);
            D[i][1] = max(D[i-1][0],D[i-1][2])+Stk[i][1];
            D[i][2] = max(D[i-1][0], D[i-1][1])+Stk[i][0];
            
            ]
        }
        return max(D[i][0], D[i][1], D[i][2]);

    }
}