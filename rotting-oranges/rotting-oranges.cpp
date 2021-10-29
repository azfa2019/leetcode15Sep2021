class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int,int>>q;
      int m=grid.size(),n=grid[0].size();
      auto fresh=false;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==2) q.push({i,j});
          if(grid[i][j]==1) fresh=true;
        }
      }
      if(q.empty()) {
        if(fresh) return -1;
        else return 0;
      }
      int ans=-1;
      while(!q.empty()){
        ans++;
        int qsize=q.size();
        for(int i=0;i<qsize;i++){
          auto cur=q.front();
          q.pop();
          int r=cur.first;
          int c=cur.second;
          if(r+1<m)if(grid[r+1][c]==1) grid[r+1][c]=2,q.push({r+1,c});
          if(r-1>=0)if(grid[r-1][c]==1) grid[r-1][c]=2,q.push({r-1,c});
          if(c+1<n)if(grid[r][c+1]==1) grid[r][c+1]=2,q.push({r,c+1});
          if(c-1>=0)if(grid[r][c-1]==1) grid[r][c-1]=2,q.push({r,c-1});
        }
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==1) return -1;
        }
      }
      return ans;
    }
};