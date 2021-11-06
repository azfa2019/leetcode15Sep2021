class Solution {
  public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    int dp[n+1][n+1][n+1];
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
        for(int x=0;x<=n;x++)
          dp[i][j][x]=INT_MIN;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        for(int x=1;x<=n;x++){
          int y=i+j-x;
          if(y<1||y>n) continue;
          if(i==1&&j==1&&x==1) {
            dp[i][j][x]=grid[0][0];
            continue;
          }
          if(grid[i-1][j-1]==-1||grid[x-1][y-1]==-1) continue;

          dp[i][j][x]=max(dp[i][j][x],dp[i-1][j][x]);
          dp[i][j][x]=max(dp[i][j][x],dp[i][j-1][x]);
          dp[i][j][x]=max(dp[i][j][x],dp[i-1][j][x-1]);
          dp[i][j][x]=max(dp[i][j][x],dp[i][j-1][x-1]);
          if(i==x && j==y) dp[i][j][x]+=grid[i-1][j-1];
          else dp[i][j][x]+=grid[i-1][j-1]+grid[x-1][y-1];
        }
    return max(0,dp[n][n][n]);
  }
};