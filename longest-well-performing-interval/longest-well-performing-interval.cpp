class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int>presum{0};
        int sum=0;
        for(int h:hours) {
            sum+=(h>8?1:-1);
            presum.push_back(sum);
        }
        stack<int>stack;
        for(int i=0;i<presum.size();i++){
            if(stack.empty() || presum[i]<presum[stack.top()]) stack.push(i);
        }
        int ans=0;
        for(int i=presum.size()-1;i>=0;i--){
            while(!stack.empty() && presum[i]>presum[stack.top()]){
                ans=max(ans,i-stack.top());
                stack.pop();
            }
        }
        return ans;
    }
};