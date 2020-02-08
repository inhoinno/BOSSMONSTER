class Solution {
    public int numJewelsInStones(String J, String S) {
        int count=0;
        for(int i=0; i<J.length(); i++){
            char jj = J.charAt(i);
            if(S.contains(J.substring(i,i+1))){
                for(int j = S.indexOf(jj); j<=S.lastindexOf(jj); j++){
                    if(jj == S.charAt(j)) count++;
                }
            }
            else continue;

        }
    }
};
