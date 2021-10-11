class Solution {
  int M=1e9+7;
public:
    int findDerangement(int n) {
      vector<long>dp(n+1,0); //dp[i]: # of derangements ending with number i
      if(n==1) return 0;
      if(n==2) return 1;
      dp[1]=0;
      dp[2]=1;
      for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-2]%M+dp[i-1]%M);
        dp[i]=dp[i]%M;
      }
      return dp[n];
    }
};
