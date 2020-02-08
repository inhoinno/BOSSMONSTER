
//1 hashmap 처음에 바로 짬 -> 4 안되서 투덱스로 다시 생각 -> 5 O(N^2), 1 6% 빠르기 
//2 다이ㅁ나믹 배웠으니 써먹자
//3 hash set 맵이랑 머가 다를까 알아보자. - twodex투덱스 용어 생성
//6 유투브의 해시셋ㅅ 을 이해하고 다시짬 -> 54_ 로
//7 88% , O(N) , P(N)
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int maxLength=0;
        int i=0;
        int j=0;
        while(j< s.length()){
            if(!set.contains(s.charAt(j))){
                set.add(s.charAt(j));
                j++;
                maxLength =Math.max(maxLength, j-i); // j-i+1일 필요가 없다. j++이 먼저 있으니까! 굉장히 센시티브 하면서 세심한 부분
            }
            else{
                set.remove(s.charAt(i));
                i++;
            }            


        }
        return maxLength;
    }
}
/* 이 문제의 제일 빠른 코드ㄷㄷㄷ

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] dict = new int[128];
        int res = 0, l = 0, r = 1;
        for(char c : s.toCharArray()) {
            l = Math.max(l, dict[c]);
            dict[c] = r;
            res = Math.max(res, r++ - l);
        }
        return res;
    }
} */