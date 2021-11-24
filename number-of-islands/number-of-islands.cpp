class Solution {
  int m,n;
  //vector<vector<char>> grid;
  int dir[5]={1,0,-1,0,1};
public:
    int numIslands(vector<vector<char>>& grid) {
      this->m=grid.size();
      this->n=grid[0].size();
      //this->grid=grid;
      int count=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]=='1') {
            dfs(i,j,grid);
            count++;
          }
        }
      }
      return count;
    }
  void dfs(int i,int j,vector<vector<char>>& grid){
    if(i<0||i>m-1||j<0||j>n-1||grid[i][j]!='1') return;
    grid[i][j]='0';
    for(int d=0;d<4;d++){
      int r=i+dir[d];
      int c=j+dir[d+1];
      dfs(r,c,grid);
    }
  }
};