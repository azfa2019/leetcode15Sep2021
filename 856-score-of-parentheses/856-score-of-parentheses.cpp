class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>stk;
        stk.push(0);
        for(auto c:s){
            if(c=='(') stk.push(0);
            else{
                int t=stk.top();
                stk.pop();
                if(t==0) stk.top()+=1;
                else stk.top()+=2*t;
            }
        }
        return stk.top();
    }
};