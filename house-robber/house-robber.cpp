class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp(n+1,INT_MIN);
      //dp[i]: max money ending with nums[i]
      nums.insert(nums.begin(),0);
      dp[0]=0;
      dp[1]=nums[1];
      for(int i=2;i<=n;i++)
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
      return dp[n];
    }
};