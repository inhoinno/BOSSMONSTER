class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {  return (s+s).substr(1,2*s.size()-1).find(s)!=s.size()-1;  }
};