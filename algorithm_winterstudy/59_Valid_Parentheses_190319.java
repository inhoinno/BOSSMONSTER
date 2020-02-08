class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        int i=0;
        if(s.length() % 2 == 0 ){
        for( i=0; i<s.length() ; i++){
            if(s.charAt(i) == '('){ st.push(')'); continue;}
            else if(s.charAt(i) == '{'){ st.push('}'); continue;}
            else if(s.charAt(i) == '['){ st.push(']'); continue;}
            
            if(s.charAt(i) !='(' || s.charAt(i) != '{'|| s.charAt(i) != '[' ){ // 닫힌 괄호 암거나 나올 경우
                if(!st.isEmpty() &&s.charAt(i) == st.peek()){
                    st.pop(); continue;
                }
            }
            
        }
        }else return false;
        return st.isEmpty();

    }
}