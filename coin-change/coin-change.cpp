class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int>dp(amount+1,0);
      return helper(coins,amount,dp);
    }
  int helper(vector<int>& coins, int amount,vector<int>&dp){
    if(amount==0) return 0;
    if(amount<0) return -1;
    if(dp[amount]!=0) return dp[amount];
    int ans=INT_MAX;
    for(int coin:coins){
      int tmp=helper(coins,amount-coin,dp);
      if(tmp<0) continue;
      ans=min(ans,tmp+1);
    }
    dp[amount]=ans==INT_MAX?-1:ans;
    return dp[amount];
  }
};