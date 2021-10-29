class Solution {
  int dirs[5]={1,0,-1,0,1};
  int m;
  public:
  int regionsBySlashes(vector<string>& grid) {
    int n=grid.size();
    vector<vector<int>>g(3*n,vector<int>(3*n,0));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(grid[i][j]=='/'){
          g[3*i][3*j+2]=1;
          g[3*i+1][3*j+1]=1;
          g[3*i+2][3*j+0]=1;
        }
        if(grid[i][j]=='\\'){
          g[3*i][3*j]=1;
          g[3*i+1][3*j+1]=1;
          g[3*i+2][3*j+2]=1;
        }
      }
    }
    m=3*n;
    int ans=0;
    for(int i=0;i<3*n;i++){
      for(int j=0;j<3*n;j++){
        if(g[i][j]==0) {
          dfs(i,j,g);
          //DFS(g,i,j);
          ans++;
        }
      }
    }
    return ans;
  }
  void DFS(vector<vector<int>>&Grid, int x, int y)
    {
        int M = Grid.size();
        if (x<0||x>=M||y<0||y>=M) return;
        if (Grid[x][y]!=0) return;
        Grid[x][y]=2;
        
        vector<pair<int,int>>dir({{0,1},{0,-1},{1,0},{-1,0}});
        for (int k=0; k<4; k++)
        {
            int i = x+dir[k].first;
            int j = y+dir[k].second;
            DFS(Grid,i,j);
        }
    }
  void dfs(int i,int j,vector<vector<int>>&g){
    if(i<0||i>m-1||j<0||j>m-1) return;
    if(g[i][j]!=0) return;
    g[i][j]=2;
    for(int d=0;d<4;d++){
      int r=i+dirs[d];
      int c=j+dirs[d+1];
      dfs(r,c,g);
    }
  }
};
// //
// /  