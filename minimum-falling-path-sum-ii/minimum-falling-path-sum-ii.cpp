class Solution {
  public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==0) {
          dp[i][j]=grid[i][j];
          continue;
        }
        int lastMin=INT_MAX;
        for(int k=0;k<j;k++){
          lastMin=min(lastMin,dp[i-1][k]);
        }
        for(int k=j+1;k<n;k++){
          lastMin=min(lastMin,dp[i-1][k]);
        }
        dp[i][j]=lastMin+grid[i][j];
      }
    }
//    for(int j=0;j<n;j++)
//      cout<<dp[1][j]<<endl;
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
      ans=min(ans,dp[n-1][i]);
    return ans;
  }
};
//dp[i][j]=min(dp[i][0]:dp[i][j-1], dp[i][j+1]:dp[i][n-1])