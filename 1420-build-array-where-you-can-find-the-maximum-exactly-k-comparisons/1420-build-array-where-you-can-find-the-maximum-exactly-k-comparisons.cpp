class Solution {
public:
    const int mod=1e9+7;
    typedef long long LL;
    int numOfArrays(int n, int m, int k) {
        if(n==1) return 0;
        LL dp[n+1][m+1][k+1];
        memset(dp,0,sizeof dp);
        for(int j=1;j<=m;j++) dp[1][j][1]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                int bound=min(min(j,i),k);
                for(int r=1;r<=bound;r++){
                    if(i==1 && r==1) continue;
                    for(int t=0;t<j;t++)
                        dp[i][j][r]=(dp[i][j][r]+dp[i-1][t][r-1])%mod;
                    dp[i][j][r]=(dp[i][j][r]+j*dp[i-1][j][r])%mod;
                }
            }
        LL ans=0;
        for(int j=1;j<=m;j++) ans=(ans+dp[n][j][k])%mod;
        return ans;
    }
};