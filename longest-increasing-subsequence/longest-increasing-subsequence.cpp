class Solution {
  public:
  int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return 1;
    int ans=INT_MIN;
    vector<int>dp(n,1);
    dp[0]=1;
    for(int i=1;i<n;i++){
      for(int j=0;j<i;j++){
        if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
      }
      ans=max(ans,dp[i]);
    }
    return ans;
  }
};