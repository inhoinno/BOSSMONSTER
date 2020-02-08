class Solution {
	public :
    bool backspaceCompare(string S, string T) {
		stack <char> ss;
		stack <char> st;
		int S_len = S.length();
		int T_len = T.length();
		for (int i = 0; i<S_len; i++){
			if (S[i] == '#') {
                if(!ss.empty()){
                    ss.pop(); continue;
                }
            }
            else ss.push(S[i]);
		}
		for (int i = 0; i<T_len; i++){
			if (T[i] == '#') {
                if(!st.empty()) {
                    st.pop(); continue;
                }
            }
            else st.push(T[i]);
		}
		if (ss.size() != st.size())
			return false;
		while (!ss.empty() && !st.empty()){
            char A = ss.top();
            char B = st.top();
            if(A != B) return false;
            ss.pop(); st.pop();
		}
		return true;
	}
};