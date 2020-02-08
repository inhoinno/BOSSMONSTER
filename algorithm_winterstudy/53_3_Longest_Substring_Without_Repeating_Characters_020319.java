
//1 hashmap 처음에 바로 짬 -> 4 안되서 투덱스로 다시 생각 -> 5 O(N^2), 1 6% 빠르기 
//2 다이ㅁ나믹 배웠으니 써먹자
//3 hash set 맵이랑 머가 다를까 알아보자. - twodex투덱스 용어 생성
//6 유투브의 해시셋ㅅ 을 이해하고 다시짬 -> 54_ 로
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int Longest_word =0; 
        int count =0;
        Map<Character, Integer> words = new HashMap<Character, Integer>();
        for(int i=0; i<s.length(); i++){
            for(int j = i; j<s.length(); j++){
                char wj = s.charAt(j);
                
                if(!words.containsKey(wj)){ //= 없다, 새로운 문자 일때
                    words.put(wj, j);
                    count = count+1;
                
                    if(Longest_word < count){
                        Longest_word = count;
                    }
                }    // 있다! = 중복된 문자 출현! 없다! = 새로운 문자 출현.
                else if(words.containsKey(wj)){ //중복된 문자. i for 로 돌아간다.
                    count =0; 
                    words.clear();
                    break; //j 탈출
               
                }
            }
        }
        return Longest_word;
    }
}