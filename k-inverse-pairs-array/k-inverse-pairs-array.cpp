class Solution {
  long M=1e9+7;
  public:
  int kInversePairs(int n, int k) {
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
        dp[i][j]= (dp[i][j-1]-(j-i>=0?dp[i-1][j-i]:0)+dp[i-1][j]+M)%M;
      }
    }
    return dp[n][k];
  }
};
//dp[i][j]: # of ways for numbers 1 to i, with j inverse pairs
// 1 2 3 4 ... i-1 
// i 1 2 3 4 ... i-1 : dp[i-1][j-(i-1)]
// 1 i 2 3 4 ... i-1 : dp[i-1][j-(i-2)]
// 1 2 3 4 ... i-1 i : dp[i-1][j]
//dp[i][j] = dp[i-1][j]+ dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-(i-1)]
//dp[i][j-1] =           dp[i-1][j-1]+ dp[i-1][j-2] + dp[i-1][j-3] + ...     + dp[i-1][j-i]
//dp[i][j]= dp[i][j-1]-dp[i-1][j-i]+dp[i-1][j]