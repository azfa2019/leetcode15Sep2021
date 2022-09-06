class Solution {
public:
    vector<vector<char>>g;
    int n,m;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    int numIslands(vector<vector<char>>& grid) {
        g=grid;
        int cnt=0;
        n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]=='1') dfs(i,j),cnt++;
        return cnt;
    }
    void dfs(int x,int y){
        g[x][y]='0';
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                int a=x+dx[i],b=y+dy[i];
                if(a>=0&&a<n&&b>=0&&b<m&&g[a][b]=='1') dfs(a,b);
            }
                
    }
};