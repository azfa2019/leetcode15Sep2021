class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp0(n,0);
        vector<int>dp1(n,0);
        dp1[0]=-prices[0];
        for(int i=1;i<n;i++){
            dp0[i]=max(dp0[i-1],dp1[i-1]+prices[i]);
            dp1[i]=max(-prices[i],dp1[i-1]);
        }
        return dp0[n-1];
    }
};