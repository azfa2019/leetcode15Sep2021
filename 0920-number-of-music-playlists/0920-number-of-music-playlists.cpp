class Solution {
public:
    typedef long long LL;
    const int N=210,mod=1e9+7;
    int numMusicPlaylists(int n, int goal, int k) {
        int f[N][N];
        f[0][0]=1;
        for(int i=1;i<=goal;i++)
            for(int j=1;j<=n&&j<=i;j++)
                f[i][j]=((LL)f[i-1][j-1]*(n-j+1)+(LL)f[i-1][j]*max(j-k,0))%mod;
        return f[goal][n];

    }
};