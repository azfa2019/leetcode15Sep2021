class Solution {
public:
    int numSquares(int n) {
      //dp[i]: min # of squares for i 
      vector<int>dp(n+1,INT_MAX/2);
      //dp[i]=dp[i-x^2]+1
      dp[0]=0;
      dp[1]=1;
      for(int i=1;i<=n;i++){
        for(int j=1;j<=sqrt(i);j++){
          dp[i]=min(dp[i],dp[i-j*j]+1);
        }
      }
      return dp[n];
    }
};