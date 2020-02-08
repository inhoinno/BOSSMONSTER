class Solution {
    
    public int[][] flipAndInvertImage(int[][] A){
        for(int i=0; i< A[0].length; i++){
             //일단 대칭으로 바까야 겠죠?
             for(int j=0; j<A[0].length/2; j++){
                 int temp = A[i][j];
                 A[i][j] = A[i][A[0].length-1-j];
                 A[i][A[0].length-1-j] = temp;
             }
             //for문을 줄이고 싶지만 .... 어쩔 수 없나?
             //java에서는 !연산자 머냐 ㅠㅠㅠㅠㅠㅠㅠㅠ
             for(int j = 0; j<A[0].length; j++){
                 A[i][j] = !(A[i][j]);
             }

        }

        return A;
    }
}