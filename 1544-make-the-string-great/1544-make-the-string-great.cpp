class Solution {
public:
    string makeGood(string s) {
        if(s==""||s.size()==1) return s;
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            if(i<s.size() && stk.size() && abs(stk.top()-s[i])==32) stk.pop();
            else stk.push(s[i]);
        }
        string res="";
        while(stk.size()) res=stk.top()+res,stk.pop();
        return res;
    }
};