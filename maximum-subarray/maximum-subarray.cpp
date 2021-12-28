class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=(dp[i-1]>0?(dp[i-1]+nums[i]):nums[i]);
            if(dp[i]>ans) ans=dp[i];
        }
        return ans;
    }
};