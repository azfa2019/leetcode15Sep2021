class Solution {
public:
  long M=1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      vector<vector<int>>dp(m,vector<int>(n,0));
      auto tmp=dp;
      for(int k=0;k<maxMove;k++){
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            long a=i-1>=0  ?dp[i-1][j]:1;
            long b=i+1<=m-1?dp[i+1][j]:1;
            long c=j-1>=0  ?dp[i][j-1]:1;
            long d=j+1<=n-1?dp[i][j+1]:1;
            tmp[i][j]=(a+b+c+d)%M;
          }
        }
        dp=tmp;
      }
      return dp[startRow][startColumn];
    }
};
