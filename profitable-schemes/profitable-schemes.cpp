class Solution {
  public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int m=group.size();
    vector<vector<int>>dp(n+1,vector<int>(minProfit+1,0));
    //dp[i][j]: max number of schemes for i people and profit j
    int M=1e9+7;
    dp[0][0]=1;
    for(int i=0;i<group.size();i++){
      int x=group[i];
      int y=profit[i];
      auto dp2=dp;
      for(int j=0;j<=n;j++){
        for(int k=0;k<=minProfit;k++){
          if(j+x<=n){
            int pp=k+y;
            pp=min(pp,minProfit);
            dp[j+x][pp]+=dp2[j][k];
            dp[j+x][pp]%=M;
          }
        }
      }
    }
    int count=0;
    for(int i=0;i<=n;i++){
      count+=dp[i][minProfit];
      count%=M;
    }
    return count;
  }
};