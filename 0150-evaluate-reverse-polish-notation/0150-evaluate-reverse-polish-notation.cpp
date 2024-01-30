class Solution {
public:
    
    int evalRPN(vector<string>& t) {
        stack<int>stk;
        for(auto& s:t){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                auto b=stk.top();stk.pop();
                auto a=stk.top();stk.pop();
                if(s=="+") a+=b;
                else if(s=="-") a-=b;
                else if(s=="*") a*=b;
                else a/=b;
                stk.push(a);
            }else stk.push(stoi(s));
        }
        return stk.top();
    }
};