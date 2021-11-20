class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>>dp(m,vector<int>(n,0));
      dp[0][0]=1;
      for(int i=0;i<m;i++) dp[i][0]=1;
      for(int i=0;i<n;i++) dp[0][i]=1;
      for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
          dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
    }
};
// m+n-2
// m-1
// (m+n-2)!/(n-1)!(m-1)!
// (m+n-2) (m+n-3) ... (n+1)(n)(n-1)(n-2).../(n-1)!(m-1)!
// (m+n-2)(m+n-3) ...(n+1)n/(m-1)!