class Solution {
  public:
  int coinChange(vector<int>& coins, int amount) {
    //top down
    vector<int>dp(amount+1,0);
    return helper(coins,dp,amount);
  }
  int helper(vector<int>& coins,vector<int>&dp, int amount){
    if(amount==0) return 0;//return 0 coins, no more coin is needed
    if(amount<0) return -1;
    if(dp[amount]!=0) return dp[amount];
    int ans=INT_MAX;
    for(int coin:coins){
      int tmp=helper(coins,dp,amount-coin);
      if(tmp<0) continue;
      ans=min(ans,tmp+1);
    }
    dp[amount]=ans==INT_MAX?-1:ans;
    return dp[amount];
  }
};