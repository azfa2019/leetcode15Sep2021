class Solution {
  public:
  double new21Game(int n, int k, int maxPts) {
    vector<double>dp(n+maxPts,1);
    for(int i=k;i<=n;i++) dp[i]=1;
    for(int i=n+1;i<n+maxPts;i++) dp[i]=0;

    double sum=0;
    for(int i=k-1;i>=0;i--){
      if(i==k-1){
        for(int j=1;j<=maxPts;j++) sum+=dp[i+j];
        dp[i]=sum/maxPts;
      }else if(i<k){
        sum-=dp[i+maxPts+1];
        sum+=dp[i+1];
        dp[i]=sum/maxPts;
      }
    }
    return dp[0];
  }
};

