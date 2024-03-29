class Solution {
public:
    int assignBikes(vector<vector<int>>& w, vector<vector<int>>& b) {
        int n=w.size(),m=b.size();
        int f[n+1][1<<m];
        memset(f,0x3f,sizeof f);
        f[0][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<1<<m;j++)
                for(int k=0;k<m;k++){
                    if(j>>k&1){
                        int d=abs(w[i-1][0]-b[k][0])+abs(w[i-1][1]-b[k][1]);
                        f[i][j]=min(f[i][j],f[i-1][j-(1<<k)]+d);
                    }
                }
        int res=1e9;
        for(int i=0;i<1<<m;i++)
            res=min(res,f[n][i]);
        return res;
    }
};