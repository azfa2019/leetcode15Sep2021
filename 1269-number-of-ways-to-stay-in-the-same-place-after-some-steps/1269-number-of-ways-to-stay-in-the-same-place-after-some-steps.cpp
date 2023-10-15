class Solution {
public:
    const int mod=1e9+7;
    int numWays(int steps, int arrLen) {
        int n=min(steps/2,arrLen-1)+1;
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=1;i<=steps;i++){
            vector<int>dp0(n);
            for(int j=0;j<n;j++){
                dp0[j]=dp[j];
                if(j-1>=0) dp0[j]=(0LL+dp0[j]+dp[j-1])%mod;
                if(j+1<=n-1) dp0[j]=(0LL+dp0[j]+dp[j+1])%mod;
            }
            dp=move(dp0);
        }
        return dp[0];
    }
};