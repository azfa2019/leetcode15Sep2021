class Solution {
  public:
  int superEggDrop(int K, int N) {

    //dp[i][j]: min # of moves for i eggs and j floors
    vector<vector<int>>dp(K+1,vector<int>(N+1,INT_MAX));
    for(int i=0;i<=K;i++)
    {
      dp[i][0]=0;
    }
    for(int i=0;i<=N;i++){
      dp[1][i]=i;
      dp[0][i]=0;
    }

    for(int k=2;k<=K;k++){
      for(int n=1;n<=N;n++){
        int l=1,r=n,m=0;
        while(l<=r){
          m=l+(r-l+1)/2;
          int b=dp[k-1][m-1],nb=dp[k][n-m];
          if(b>nb) r=m-1;
          else l=m+1;
          dp[k][n]=min(dp[k][n],max(b,nb)+1);
        }
        //for(int i=1;i<=n;i++){
        //  dp[k][n]=min(dp[k][n],max(dp[k-1][i-1]+1,dp[k][n-i]+1));
        //}
      }
    }
    return dp[K][N];
  }
};