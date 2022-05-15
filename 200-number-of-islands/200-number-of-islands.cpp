class Solution {
    vector<vector<char>>g;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
public:
    int numIslands(vector<vector<char>>& grid) {
        g=grid;
        int cnt=0;
        for(int i=0;i<g.size();i++)
            for(int j=0;j<g[0].size();j++)
                if(g[i][j]=='1') {
                    dfs(i,j);
                    cnt++;
                }
        return cnt;
    }
    void dfs(int x,int y){
        g[x][y]=0;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<g.size() && ny>=0 && ny<g[0].size() && g[nx][ny]=='1') dfs(nx,ny);
        }
    }
};