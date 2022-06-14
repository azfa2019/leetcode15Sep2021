class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        vector<vector<int>>f(n+1,vector<int>(m+1));
        //w1="#"+w1;
        //w2="#"+w2;
        //f[0][0]=0;
        for(int i=1;i<=n;i++) f[i][0]=i;
        for(int i=1;i<=m;i++) f[0][i]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1]) f[i][j]=f[i-1][j-1];
                else f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            }
        return f[n][m];
    }
};