class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        vector<int>f(t+1);
        const int mod=1e9+7;
        f[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=t;j>=0;j--){
                f[j]=0;
                for(int u=1;u<=k&&u<=j;u++)
                    f[j]=(f[j]+f[j-u])%mod;
            }
        return f[t];
    }
};