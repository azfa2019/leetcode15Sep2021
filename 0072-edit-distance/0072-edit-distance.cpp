class Solution {
    public:
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        w1="#"+w1,w2="#"+w2;
        vector<vector<int>>f(n+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++) f[0][i]=i;
        for(int i=1;i<=n;i++) f[i][0]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                f[i][j]=min(f[i-1][j],f[i][j-1])+1;
                if(w1[i]==w2[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
                else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
            }
        return f[n][m];
    }
};