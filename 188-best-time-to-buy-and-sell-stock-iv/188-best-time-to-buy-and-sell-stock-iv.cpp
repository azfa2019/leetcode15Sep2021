class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int INF=1e8;
        int n=prices.size();
        if(k>=n/2){
            int res=0;
            for(int i=0;i+1<n;i++) 
                if(prices[i+1]>prices[i]) res+=prices[i+1]-prices[i];
            return res;
        }
        vector<vector<int>>f(n+1,vector<int>(k+1,-INF));
        auto g=f;
        f[0][0]=0;
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++){
                f[i][j]=max(f[i-1][j],g[i-1][j]+prices[i-1]);
                g[i][j]=g[i-1][j];
                if(j) g[i][j]=max(g[i][j],f[i-1][j-1]-prices[i-1]);
                res=max(res,f[i][j]);
            }
        return res;
    }
};