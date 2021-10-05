class Solution {
  public:
  int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    vector<vector<int>>dp(n,vector<int>(n,0));//dp[i][j]: max money in interval i:j
    for(int i=0;i<n;i++) dp[i][i]=nums[i];
    for(int len=2;len<=n;len++){
      for(int i=0;i+len-1<=n-1;i++){
        int j=i+len-1;
        dp[i][j]=max(dp[i+1][j],nums[i]+((i+2==n)?0:dp[i+2][j])); //when len=2, j=i+1
      }
    }
    return max(dp[0][n-2],dp[1][n-1]);
  }
};

