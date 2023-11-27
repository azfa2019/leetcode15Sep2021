class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> f(n,vector<int>(10));
        for(int i=0;i<10;i++) f[0][i]=1;
        const int mod=1e9+7;
        vector<int>tr[10]={
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {3,9,0},
            {},
            {1,7,0},
            {2,6},
            {1,3},
            {2,4},
        };
        for(int i=1;i<n;i++)
            for(int j=0;j<10;j++)
                for(int k:tr[j])
                    f[i][j]=(f[i][j]+f[i-1][k])%mod;
        int res=0;
        for(int i=0;i<10;i++) res=(res+f[n-1][i])%mod;
        return res;
    }
};