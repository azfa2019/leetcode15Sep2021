class Solution {
  public:
  int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<int>dp(amount+1,INT_MAX/2);
    dp[0]=0;
    for(int i=0;i<=amount;i++){
      for(int j=0;j<n;j++){
        if(i-coins[j]>=0)
          dp[i]=min(dp[i],dp[i-coins[j]]+1);
      }
    }
    return dp[amount]==INT_MAX/2?-1:dp[amount];
  }
};