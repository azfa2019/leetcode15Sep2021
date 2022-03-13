class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        if(s[0]==']'||s[0]==')'||s[0]=='}') return false;
        for(auto c:s){
            if(c=='('||c=='['||c=='{') stk.push(c);
            else if(c==')') {
                if(stk.empty() || stk.top()!='(') return false;
                stk.pop();
            }else if(c==']'){
                if(stk.empty() || stk.top()!='[') return false;
                stk.pop();
            }else if(c=='}'){
                if(stk.empty() || stk.top()!='{') return false;
                stk.pop();
            }
        }
        return stk.size()==0;
    }
};