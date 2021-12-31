class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,minP=prices[0];
        for(int p:prices){
            minP=min(p,minP);
            ans=max(ans,p-minP);
        }
        return ans;
    }
};