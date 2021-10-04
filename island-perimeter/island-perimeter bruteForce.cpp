class Solution {
  public:
  int m,n;
  int islandPerimeter(vector<vector<int>>& grid) {
    m=grid.size(),n=grid[0].size();
    int count=0,shared=0;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(grid[i][j]==1) {
          count++;
          if(check(i+1,j,grid)) shared++;
          if(check(i-1,j,grid)) shared++;
          if(check(i,j+1,grid)) shared++;
          if(check(i,j-1,grid)) shared++;
        }
      }
    }
    return count*4-shared;
  }
  bool check(int r,int c,vector<vector<int>>&grid){
    if(r<0||r>m-1||c<0||c>n-1) return false;
    if(grid[r][c]==1) return true;
    return false;
  }
};
