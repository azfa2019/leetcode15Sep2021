class Solution {
    int ans;
    vector<int> coins;
    vector<int> dp;
    public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins=coins;
        this->dp=vector<int>(amount+1,0);
        return helper(amount);
    }
    int helper(int amount){
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(dp[amount]!=0) return dp[amount];
        int ans=INT_MAX;

        for(int c:coins){
            int tmp=helper(amount-c);
            if(tmp!=-1){
                ans=min(ans,tmp+1);
            }
        }
        dp[amount]=((ans==INT_MAX)?-1:ans);
        return dp[amount];
    }
};