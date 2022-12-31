class Solution {
public:
    int n,m,k;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    vector<vector<int>>g;
    int dfs(int x,int y){
        if(g[x][y]==2){
            if(!k) return 1;
            return 0;
        }
        g[x][y]=-1,k--;
        int res=0;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<n&&b>=0&&b<m&&g[a][b]!=-1)
                res+=dfs(a,b);
        }
        g[x][y]=0,k++;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        g=grid;
        n=g.size(),m=g[0].size(),k=0;
        int sx,sy;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]==1) sx=i,sy=j,k++;
                else if(!g[i][j]) k++;
        return dfs(sx,sy);
    }
};