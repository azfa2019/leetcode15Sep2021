class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk;
        unordered_map<char,int>last;
        unordered_map<char,bool>ins;
        for(int i=0;i<s.size();i++) last[s[i]]=i;
        for(int i=0;i<s.size();i++){
            if(ins[s[i]]) continue;
            while(stk.size() && stk.back()>s[i] && last[stk.back()]>i){
                ins[stk.back()]=false;
                stk.pop_back();
            }
            ins[s[i]]=true;
            stk+=s[i];
        }
        return stk;
    }
};