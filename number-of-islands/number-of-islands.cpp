class Solution {
  public:
  int m,n;
  int dir[5]={1,0,-1,0,1};
  int numIslands(vector<vector<char>>& grid) {
    m=grid.size(),n=grid[0].size();
    int count=0;
    for(int r=0;r<m;r++)
      for(int c=0;c<n;c++){
        if(grid[r][c]=='1') {
          dfs(r,c,grid);
          count++;
        }
      }
    return count;

  }
  void dfs(int row,int col,vector<vector<char>>& grid){
    if(row<0||row>m-1||col<0||col>n-1||grid[row][col]=='0') return;
    grid[row][col]='0';
    for(int i=0;i<4;i++){
      int rn=row+dir[i];
      int cn=col+dir[i+1];
      dfs(rn,cn,grid);
    }
  }
};