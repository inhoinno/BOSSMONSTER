import java.util.*;

class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {

        List<String> result = new ArrayList<>();

        for(String w : words){
            Map<Character, Character> map = new HashMap<Character, Character>();
            int len = w.length();
            int i;
            for(i = 0 ; i < len ; i++){
                Character pp = pattern.charAt(i);
                Character word = w.charAt(i);

                if(map.get(pp) == null){
                    // 새로운 짝
                    if(!map.containsValue(word)){
                        map.put(pp, word);
                    } else {
                        break;
                    }
                } else if(!map.get(pp).equals(word)){
                    // 이미 있으면 비교하기
                    break;
                }
            }

            if(i < len){
                continue;
            }

            result.add(w);
        }

        return result;
    }
}