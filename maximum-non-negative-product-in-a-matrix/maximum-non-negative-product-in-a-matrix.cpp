typedef long long ll;
class Solution {
  ll M=1e9+7;
  public:
  int maxProductPath(vector<vector<int>>& grid) {
    //dp1[i][j]=min(dp1[i-1][j]*grid[i][j],dp2[i-1][j]*grid[i][j])
    //dp2[i][j]=max(dp1[i-1][j]*grid[i][j],dp2[i-1][j]*grid[i][j])
    int m=grid.size(),n=grid[0].size();
    vector<vector<ll>>dp1(m,vector<ll>(n));
    vector<vector<ll>>dp2(m,vector<ll>(n));
    dp1[0][0]=grid[0][0];
    dp2[0][0]=grid[0][0];
    for(int j=1;j<n;j++) {
      dp1[0][j]=dp1[0][j-1]*grid[0][j];
      dp2[0][j]=dp2[0][j-1]*grid[0][j];
    }
    for(int i=1;i<m;i++) {
      dp1[i][0]=dp1[i-1][0]*grid[i][0];
      dp2[i][0]=dp2[i-1][0]*grid[i][0];
    }
    for(int i=1;i<m;i++){
      for(int j=1;j<n;j++){
        dp1[i][j]=min({dp1[i-1][j]*grid[i][j],dp2[i-1][j]*grid[i][j],dp1[i][j-1]*grid[i][j],dp2[i][j-1]*grid[i][j]});
        dp2[i][j]=max({dp1[i-1][j]*grid[i][j],dp2[i-1][j]*grid[i][j],dp1[i][j-1]*grid[i][j],dp2[i][j-1]*grid[i][j]});
        //dp1[i][j]%=M;
        //dp2[i][j]%=M;
        //cout<<i<<";"<<j<<endl;
        //cout<<dp1[i][j]<<","<<dp2[i][j]<<endl;
      }
    }
    //cout<<dp1[m-1][n-1]<<","<<dp2[m-1][n-1]<<endl;
    int ans=dp2[m-1][n-1]%M;
    return ans>=0?ans:-1;
  }
};