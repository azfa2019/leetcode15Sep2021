class Solution {
  long dp[1001][1001];
  long sum[1001][1001];
  long M=1e9+7;
public:
    int numberOfSets(int n, int K) {
      //dp[i][k]: # of ways to draw k lines for points 0-i, 
      // x x x i  if drawing a line to point i
      //      -  dp[i-1][k-1]
      //    - -  dp[i-2][k-1]
      //- - - -  dp[0][k-1]
      // x x x i  if not drawing a line to point i
      // x x x i dp[i-1][k]
      
      //dp[0][i]=0; by default
      for(int i=0;i<n;i++){
        dp[i][0]=1;
        sum[i][0]=i+1;
      }
      for(int i=1;i<n;i++){
        for(int k=1;k<=K;k++){
          dp[i][k]=sum[i-1][k-1]+dp[i-1][k];
          dp[i][k]%=M;
          sum[i][k]=sum[i-1][k]+dp[i][k];
          sum[i][k]%=M;
          //for(int j=0;j<i;j++){
          //  dp[i][j]+=dp[j][k-1]+dp[i-1][k];
          //}
        }
      }
      return dp[n-1][K]%M;
        
    }
};