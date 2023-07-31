class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int n=a.size(),m=b.size();
        a=' '+a,b=' '+b;
        vector<vector<int>>f(n+1,vector<int>(m+1,INT_MAX));
        f[0][0]=0;
        for(int i=1;i<=n;i++) f[i][0]=f[i-1][0]+a[i];
        for(int i=1;i<=m;i++) f[0][i]=f[0][i-1]+b[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(a[i]==b[j]) f[i][j]=f[i-1][j-1];
                else {
                    f[i][j]=min(f[i-1][j]+a[i],f[i][j-1]+b[j]);
                    f[i][j]=min(f[i][j],f[i-1][j-1]+a[i]+b[j]);
                }
            }
        return f[n][m];
    }
};