class Solution {
  public:
  int twoEggDrop(int n) {
    vector<vector<int>>dp(3,vector<int>(n+1,INT_MAX/2));//dp[i][j]: min # of moves with i eggs (i=1 or 2) and j floors
    //int dp[3][n+1];
    dp[1][0]=0;
    dp[2][0]=0;
    for(int i=1;i<=n;i++) dp[1][i]=i;

    for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
        int a=dp[1][j-1];
        int b=dp[2][i-j];
        dp[2][i]=min(dp[2][i],max(a,b)+1); 
      }
      //first egg broken at j, dp[1][j-1]+1
      //first egg not broken at j, dp[1][i-j]+1
    }
    return dp[2][n];

  }
};