class Solution {
  public:
  int minScoreTriangulation(vector<int>& values) {
    int n=values.size();
    vector<vector<int>>dp(n,vector<int>(n,INT_MAX/3));
    //bc: when len=2
    for(int i=0;i<n-1;i++) dp[i][i+1]=0;
    for(int len=3;len<=n;len++){
      for(int i=0;i+len-1<=n-1;i++){
        int j=i+len-1;
        for(int k=i+1;k<=j-1;k++)
          dp[i][j]=min(dp[i][j],dp[i][k]+values[i]*values[j]*values[k]+dp[k][j]);
      }
    }
    return dp[0][n-1];
  }
};