class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k=0;
        stack<int>stk;
        for(int x:pushed){
            stk.push(x);
            while(stk.size() && stk.top()==popped[k]) {
                stk.pop();
                k++;
            }
        }
        return k==popped.size();
    }
};
