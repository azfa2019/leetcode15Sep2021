class Solution {
    public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto c:s){
            if(c=='('||c=='[' || c=='{') stk.push(c);
            else{
                if(c==')'){
                    if(stk.empty() || stk.top()!='(') return false;
                }
                else if(c==']'){
                    if(stk.empty()||stk.top()!='[') return false;
                }
                else if(c=='}'){
                    if(stk.empty()||stk.top()!='{') return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};