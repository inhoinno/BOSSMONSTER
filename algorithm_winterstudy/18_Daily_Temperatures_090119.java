class Solution {
    public int[] dailyTemperatures(int[] T) {
        
        int t_len=T.length;
        int[] Days =new int[t_len];
        int count=0;
        for(int i=0; i<t_len-1; i++){
            for(int j=i+1; j<t_len; j++){
                if(T[i] <T[j]){
                    count++;
                    Days[i] = count;
                    count=0;
                    break;
                }
                else count++;
            }
        }
        Days[t_len-1] = 0;
        return Days;
    }
}
//stack[++top] 이건 어때
