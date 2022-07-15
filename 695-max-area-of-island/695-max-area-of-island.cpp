class Solution {
public:
    int n,m;
    vector<vector<int>>g;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    int dfs(int x,int y){
        g[x][y]=0;
        int res=1;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a<n && a>=0 && b<m && b>=0 && g[a][b]) res+=dfs(a,b);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g=grid;
        int res=0;
        n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]) res=max(res,dfs(i,j));
        return res;
    }
};