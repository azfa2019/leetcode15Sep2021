class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod=1e9+7;
        vector<vector<int>>f(n+1,vector<int>(5));
        int g[5][5]={
            {0,1,0,0,0},
            {1,0,1,0,0},
            {1,1,0,1,1},
            {0,0,1,0,1},
            {1,0,0,0,0}
        };
        for(int i=0;i<5;i++) f[1][i]=1;
        for(int i=2;i<=n;i++)
            for(int j=0;j<5;j++)
                for(int k=0;k<5;k++)
                    if(g[k][j])
                        f[i][j]=(f[i][j]+f[i-1][k])%mod;
        int res=0;
        for(int i=0;i<5;i++) res=(res+f[n][i])%mod;
        return res;
    }
};