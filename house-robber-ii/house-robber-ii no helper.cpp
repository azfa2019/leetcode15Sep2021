class Solution {
  public:
  int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    nums.insert(nums.begin(),0);
    vector<int>dp(n+1,0);
    dp[1]=nums[1];
    for(int i=2;i<=n-1;i++){
      dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    vector<int>dp2(n+1,0);
    for(int i=2;i<=n;i++){
      dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
    }
    return max(dp[n-1],dp2[n]);
  }
};
