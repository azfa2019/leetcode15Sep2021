class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,bool>ins;
        unordered_map<char,int>pos;
        string stk;
        int n=s.size();
        for(int i=0;i<n;i++) pos[s[i]]=i;
        for(int i=0;i<n;i++){
            if(ins[s[i]]) continue;
            while(stk.size() && stk.back()>s[i] && pos[stk.back()]>i) ins[stk.back()]=false, stk.pop_back();
            ins[s[i]]=true;
            stk+=s[i];
        }
        return stk;
    }
};