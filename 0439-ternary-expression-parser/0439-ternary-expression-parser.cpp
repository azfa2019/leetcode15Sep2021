class Solution {
public:
    string parseTernary(string e) {
        stack<char>stk;
        for(int i=e.size()-1;i>=0;i--){
            char c=e[i];
            if(stk.size()&&stk.top()=='?'){
                stk.pop();
                char first=stk.top();stk.pop();
                stk.pop();
                char second=stk.top();stk.pop();
                if(c=='T') stk.push(first);
                else stk.push(second);
            }else stk.push(c);
        }
        string res="";
        res+=stk.top();
        return res;
    }
};