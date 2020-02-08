import java.util.*;
class Solution {
public int uniqueMorseRepresentations(String[] words) {
         List<String> ll = new ArrayList<>();
         Map<Character, String> map = new HashMap<Character, String>();
         map.put('a', ".-");
         map.put('b', "-...");
         map.put('c', "-.-.");
         map.put('d', "-..");
         map.put('e', ".");
         map.put('f', "..-");
         map.put('g', "--.");
         map.put('h', "....");
         map.put('i', "..");
         map.put('j', ".---");
         map.put('k', "-.-");
         map.put('l', ".-..");
         map.put('m', "--");
         map.put('n', "-.");
         map.put('o', "---");
         map.put('p', "--");
         map.put('q', "--.-");
         map.put('r', ".-.");
         map.put('s', "...");
         map.put('t', "-");
         map.put('u', "..-");
         map.put('v', "...-");
         map.put('w', ".--");
         map.put('x', "-..-");
         map.put('y', "-.-");
         map.put('z', "--..");

         for(String w : words){
                
             int len = w.length();
             w.toLowerCase();
             String str = new String("");
             for(int i=0; i<len ; i++){
                 char ch = w.charAt(i);
                 if(map.containsKey(ch)){// 있겄쥬
                    str = str.concat(map.get(ch));
                    //str에는 해당 문자열w의 모스부호가 들감.
                 }
                 else return -1;
            }
                
            if(!ll.contains(str)){ //새로운건디요?
                ll.add(str);
                
            }
            else continue; //같은거있따
        }
        return ll.size();
}
}