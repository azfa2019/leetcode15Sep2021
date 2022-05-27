class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        vector<int>f(m+1,1e9);
        f[0]=0;
        for(int c:coins)
            for(int i=c;i<=m;i++)
                f[i]=min(f[i],f[i-c]+1);
        return f[m]==1e9?-1:f[m];
    }
};