class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp0(n,0); //no stock
        vector<int>dp1(n,0); //with stock
        dp1[0]=-prices[0];
        dp0[0]=0;
        for(int i=1;i<n;i++){
            dp1[i]=max(-prices[i],dp1[i-1]);
            dp0[i]=max(dp0[i-1],dp1[i-1]+prices[i]);
        }
        return dp0[n-1];
    }
};
// states: 
// stock:with stock, without stock
// no stock: never had stock, or sold stock
