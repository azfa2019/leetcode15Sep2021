class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
      int M=1e9+7;
      vector<vector<long>>dp(goal+1,vector<long>(n+1,0));
      //dp[i][j]: # of playlists, each playlist has i songs from j different songs 
      dp[1][1]=n;
      for(int i=2;i<=goal;i++){
        for(int j=1;j<=n;j++){
          if(n-j+1>0)
            dp[i][j]+=dp[i-1][j-1]*(n-j+1);
          dp[i][j]%=M;
          if(j>k)
            dp[i][j]+=dp[i-1][j]*(j-k);
          dp[i][j]%=M;
        }
      }
      return dp[goal][n];
    }
};