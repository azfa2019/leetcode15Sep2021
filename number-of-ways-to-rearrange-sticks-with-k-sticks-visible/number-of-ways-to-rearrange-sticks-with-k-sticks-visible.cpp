class Solution {
  long dp[1001][1001];
  long M=1e9+7;
public:
    int rearrangeSticks(int n, int k) {
      dp[0][0]=1;
      for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
          dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*(i-1))%M;
          }
        }
      return dp[n][k];
    }
};
