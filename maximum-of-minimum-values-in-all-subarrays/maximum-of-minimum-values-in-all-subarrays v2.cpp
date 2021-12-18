class Solution {
    public:
    vector<int> findMaximums(vector<int>& nums) {
        int n=nums.size();
        vector<int>prevLess(n,-1);
        vector<int>nextLess(n,n);
        stack<int>stck;
        for(int i=0;i<n;i++){
            while(!stck.empty() && nums[stck.top()]>nums[i]){
                nextLess[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        while(!stck.empty()) stck.pop();
        for(int i=n-1;i>=0;i--){
            while(!stck.empty() && nums[stck.top()]>nums[i]){
                prevLess[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int len=nextLess[i]-prevLess[i]-1;
            ans[len-1]=max(ans[len-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i+1],ans[i]);
        }
        return ans;
    }
};
// 10 20 10 50 40 10
// 10 20 10 50 10 40
// query i: size=i+1
// i=1, 
