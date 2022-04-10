class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>stk;
        for(auto e:ops){
            if(e[0]=='+') {
                int n1=stk.top();stk.pop();
                int n2=stk.top();stk.pop();
                int s=n1+n2;
                stk.push(n2);
                stk.push(n1);
                stk.push(s);
            }else if(e[0]=='D'){
                int s=stk.top()*2;
                stk.push(s);
            }else if(e[0]=='C') stk.pop();
            else stk.push(stoi(e));
        }
        int sum=0;
        while(stk.size()) sum+=stk.top(),stk.pop();
        return sum;
    }
};