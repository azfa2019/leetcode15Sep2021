class Solution {
  public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1,INT_MAX/2);
    //dp[i]: # of minimum coins to get to a total of i
    dp[0]=0;
    for(int i=0;i<=amount;i++){
      for(int coin:coins){
        if(i-coin<0) continue;
        dp[i]=min(dp[i],dp[i-coin]+1);
      }
    }
    return dp[amount]==INT_MAX/2?-1:dp[amount];
  }
};
