class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.size() || !t.size()) return s.size()<=t.size();
        int i=0,j=0;
        for(j=0;j<t.size();j++){
            if(t[j]==s[i]) i++;
        }
        return i==s.size();
    }
};