class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int min=0,fresh=0;
      queue<pair<int,int>>q;
      int m=grid.size(),n=grid[0].size();
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==2) q.push({i,j});
          else if(grid[i][j]==1) fresh++;
        }
      }
      vector<pair<int,int>>dirs{{-1,0},{1,0},{0,-1},{0,1}};
      while(!q.empty()){
        int qsize=q.size();
        bool rotten=false;
        for(int i=0;i<qsize;i++){
          auto cur=q.front();
          q.pop();
          for(auto d:dirs){
            int i=cur.first+d.first;
            int j=cur.second+d.second;
            if(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]==1){
              grid[i][j]=2;
              q.push({i,j});
              fresh--;
              rotten=true;
            }
          }
        }
        if(rotten) min++;
      }
      return fresh?-1:min;
    }
};