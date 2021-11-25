class Solution {
  public:
  int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    nums.insert(nums.begin(),0);
    vector<int>dp(n+1,0);
    int ans=INT_MIN;
    dp[0]=0;
    for(int i=1;i<=n;i++){
      dp[i]=max(dp[i-1]+nums[i],nums[i]);
      ans=max(ans,dp[i]);
    }
    return ans;
  }
};