class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size(),m=accumulate(rods.begin(),rods.end(),0);
        vector<vector<int>>f(n+1,vector<int>(m*2+1,-1e8));
        f[0][m]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m*2;j++){
                int x=rods[i-1];
                f[i][j]=f[i-1][j];
                if(j-x>=0) f[i][j]=max(f[i][j],f[i-1][j-x]+x);
                if(j+x<=2*m) f[i][j]=max(f[i][j],f[i-1][j+x]);
            }
        return f[n][m];
    }
};