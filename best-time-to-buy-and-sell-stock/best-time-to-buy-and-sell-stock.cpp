class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> hold(n,0),noHold(n,0);
        hold[0]=-prices[0];
        noHold[0]=0;
        for(int i=1;i<n;i++){
            hold[i]=max(hold[i-1],-prices[i]);
            noHold[i]=max(hold[i-1]+prices[i],noHold[i-1]);
        }
        return noHold[n-1];
    }
};