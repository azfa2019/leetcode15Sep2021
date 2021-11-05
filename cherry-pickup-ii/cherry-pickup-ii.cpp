class Solution {
  public:
  int cherryPickup(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
    //dp[r][i][j]: max sum at row r, when robots are at col i & j 
    dp[0][n-1]=grid[0][0]+grid[0][n-1];
    for(int r=1;r<m;r++){
      auto dp_old=dp;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          for(int a=i-1;a<=i+1;a++){
            for(int b=j-1;b<=j+1;b++){
              if(a<0||a>n-1||b<0||b>n-1) continue;
              if(i!=j)
                dp[i][j]=max(dp[i][j],dp_old[a][b]+grid[r][i]+grid[r][j]);
              else
                dp[i][j]=max(dp[i][j],dp_old[a][b]+grid[r][i]);
            }
          }
        }
      }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        ans=max(ans,dp[i][j]);
    return ans;
    }
};
//dp1[i][j]=max(dp1[i-1][j-1], dp1[i-1][j],dp1[i-1][j+1]) +grid[i][j];
//dp2[i][j]=max(dp2[i-1][j-1], dp2[i-1][j],dp2[i-1][j+1]) +grid[i][j];
