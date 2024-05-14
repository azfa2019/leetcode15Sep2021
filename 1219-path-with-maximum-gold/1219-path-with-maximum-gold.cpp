class Solution {
public:
    int n,m;
    vector<vector<int>>g;
    int ans=0;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    int getMaximumGold(vector<vector<int>>& grid) {
        g=grid;
        n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]) dfs(i,j,0);
        return ans;
    }
    void dfs(int x,int y,int sum){
        int w=g[x][y];
        sum+=w;
        ans=max(ans,sum);
        g[x][y]=0;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<n&&b>=0&&b<m&&g[a][b])
                dfs(a,b,sum);
            
        }
        g[x][y]=w;
    }
};