class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        nums.insert(nums.begin(),0);
        vector<int>dp(n+1,0);
        dp[1]=nums[1];
        for(int i=2;i<=n-1;i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        int op1=dp[n-1];
        dp[1]=0,dp[2]=nums[2];
        for(int i=3;i<=n;i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        int op2=dp[n];
        return max(op1,op2);
    }
};