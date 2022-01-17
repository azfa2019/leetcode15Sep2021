class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),0);
        vector<int>dp(n+1,0);
        dp[1]=nums[1];
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n];
    }
};