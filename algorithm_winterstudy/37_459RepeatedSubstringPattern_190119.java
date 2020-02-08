//자신을 제외한 최대 공약수
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String clue =new String();
        int len = s.length();
        for(int i=0; i<len/2+1; i++){
            if(i != len/2 +1){
                clue = s.substring(0, i+1);
                if(len % clue.length()==0) //적당한 길이의 clue가 채워졌을때
                {
                    int j; 
                    for( j=0; j< len / clue.length() -1; j++){
                        if(clue.equals(s.substring((j+1)*clue.length(), (j+2)*clue.length()))){
                            if( j == len / clue.length() - 2) return true;
                        } //이때 i는 clue.length랑 같음 clue true 면
                        else break; //clue 부족
                        continue;
                    }
                    
                }
                else continue;
                

            }
            else return false;
        }
        
        return false;
    }
}
//Runtiem 131 faster than 17.96%