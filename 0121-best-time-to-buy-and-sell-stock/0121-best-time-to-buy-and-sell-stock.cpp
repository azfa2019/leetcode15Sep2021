class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minV=prices[0],res=0;
        for(auto x:prices) minV=min(minV,x),res=max(res,x-minV);
        return res;
    }
};