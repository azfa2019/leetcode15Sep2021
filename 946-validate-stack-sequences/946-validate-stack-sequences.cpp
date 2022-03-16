class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k=0;
        stack<int>stk;
        for(auto x:pushed){
            stk.push(x);
            while(stk.size() && stk.top()==popped[k])
                k++,stk.pop();
        }
        return k==popped.size();
    }
};