class Solution {
public:
    int n,m;
    vector<vector<int>>g,dist;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    queue<pair<int,int>>q;
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        g=grid;
        dist=vector<vector<int>>(n,vector<int>(m,1e8));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(g[i][j]){
                    dfs(i,j);
                    return bfs();
                }
            }
        return -1;
    }
    void dfs(int x,int y){
        g[x][y]=0;
        dist[x][y]=0;
        q.push({x,y});
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<n&&b>=0 && b<m && g[a][b]) dfs(a,b);
        }
    }
    int bfs(){
        while(q.size()){
            auto t=q.front();q.pop();
            for(int i=0;i<4;i++){
                int x=t.first+dx[i],y=t.second+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && dist[x][y]>dist[t.first][t.second]+1){
                    dist[x][y]=dist[t.first][t.second]+1;
                    if(g[x][y]) return dist[x][y]-1;
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
};