class Solution {
  int m,n;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
      m=grid.size(),n=grid[0].size();
      int step=1,startx,starty;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==1) {
            startx=i,starty=j;
         //   continue;
          }
          if(grid[i][j]==0) step++;
        }
      }
      return dfs(startx,starty,grid,step);
    }
  int dfs(int x,int y,vector<vector<int>>& grid,int step){
    if(x<0||x>m-1||y<0||y>n-1||grid[x][y]==-1) return 0;
    if(grid[x][y]==2) return step==0?1:0;
    grid[x][y]=-1;
    int ans=0;
    ans+=dfs(x-1,y,grid,step-1);
    ans+=dfs(x+1,y,grid,step-1);
    ans+=dfs(x,y-1,grid,step-1);
    ans+=dfs(x,y+1,grid,step-1);
    grid[x][y]=0;
    return ans;
  }
};