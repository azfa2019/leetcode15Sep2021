class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
      int n=stones.size();
      stones.insert(stones.begin(),0);
      vector<int>presum(n+1,0);
      for(int i=1;i<=n;i++){
        presum[i]=presum[i-1]+stones[i];
      }
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      //dp[i][j]: max difference for stones[i:j]
      for(int i=1;i<=n;i++) dp[i][i]=0;
      for(int i=1;i+1<=n;i++) dp[i][i+1]=max(stones[i],stones[i+1]);
      for(int len=3;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
          int j=i+len-1;
          dp[i][j]=max(presum[j]-presum[i]-dp[i+1][j],presum[j-1]-presum[i-1]-dp[i][j-1]);
        }
      }
      return dp[1][n];
        
    }
};
