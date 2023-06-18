class Solution {
public:
    const int mod=1e9+7;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    int countPaths(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        int f[n][m];memset(f,-1,sizeof f);
        function<int(int,int)>dfs=[&](int x,int y)->int{
            if(f[x][y]!=-1) return f[x][y];
            int res=1;
            for(int i=0;i<4;i++){
                int a=x+dx[i],b=y+dy[i];
                if(a>=0 && a<n && b>=0 && b<m && g[a][b]<g[x][y])
                    res=(res+dfs(a,b))%mod;
            }
            return f[x][y]=res;
        };
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=(ans+dfs(i,j))%mod;
        return ans;
    }
};