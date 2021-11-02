class Solution {
  int dp[101][101];
  public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
    for(int i=0;i<n;i++){
      dp[0][i]=matrix[0][i];
    }
    for(int i=1;i<n;i++){
      for(int j=0;j<n;j++){
        dp[i][j]=dp[i-1][j];
        if(j-1>=0)
          dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        if(j+1<=n-1)
          dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
        dp[i][j]+=matrix[i][j];
      }
    }
    int ans=INT_MAX/2;
    for(int j=0;j<n;j++){
      ans=min(ans,dp[n-1][j]);
    }
    return ans;
  }
};
//dp1[i][j]=dp[i-1][j-1]+matrix[i][j] 
//dp2[i][j]=dp[i-1][j+1]+matrix[i][j]
//dp3[i][j]=dp[i-1][j]+matrix[i][j]
