class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>f(amount+1,1e8);
        f[0]=0;
        for(int c:coins){
            for(int j=c;j<=amount;j++)
                f[j]=min(f[j],f[j-c]+1);
        }
        if(f[amount]==1e8) return -1;
        return f[amount];
    }
};