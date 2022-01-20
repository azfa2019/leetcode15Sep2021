class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>mem(amount+1,0);
        dfs(amount,coins,mem);
        return mem[amount];
    }
    int dfs(int amount,vector<int>&coins,vector<int>&mem){
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(mem[amount]!=0) return mem[amount];
        int ans=INT_MAX;
        for(int c:coins){
            int tmp=dfs(amount-c,coins,mem);
            if(tmp>=0) ans=min(ans,tmp+1);
        }
        mem[amount]=ans==INT_MAX?-1:ans;
        return mem[amount];
    }
};