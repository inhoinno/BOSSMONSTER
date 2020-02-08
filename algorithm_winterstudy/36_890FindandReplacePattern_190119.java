class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList<>();
        for(String w : words){
            Map<Character, Character> map = new HashMap<Character,Character>();
            for(int i=; i< w.length(); i++){
                Character pp= pattern.charAt(i);
                Character word = words.charAt(i);

                if(map.get(pp) == null){ //패턴 짝이 없음 = 새로운 짝
                    if(!map.containsValue(word)){
                        map.put(pp,word);
                    }
                    else break;

                }
                else if(!map.get(pp).equals(word)) // 이미 잇으면 밸류랑 비교
                    break; 
                
            }
            if(i<w.length()){
                continue;
            }
            result.add(w);



        }
        return result;
    }
}
public int main (args[]){

}