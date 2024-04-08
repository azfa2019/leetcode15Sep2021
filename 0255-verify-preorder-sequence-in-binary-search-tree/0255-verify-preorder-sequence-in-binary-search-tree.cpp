class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int>stk;
        int low=INT_MIN;
        for(int x:preorder){
            if(x<low) return false;
            while(stk.size()&&x>stk.top()) low=stk.top(),stk.pop();
            stk.push(x);
        }
        return true;
    }
};