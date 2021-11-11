class Solution {
  int m,n;
  vector<vector<int>>pac,atl;
  int dir[5]={1,0,-1,0,1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      m=heights.size();
      n=heights[0].size();
      pac.resize(m,vector<int>(n));
      atl.resize(m,vector<int>(n));
      for(int i=0;i<m;i++){
        dfs(i,0,heights,pac);
        dfs(i,n-1,heights,atl);
      }
      for(int j=0;j<n;j++){
        dfs(0,j,heights,pac);
        dfs(m-1,j,heights,atl);
      }
      vector<vector<int>>ans;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(pac[i][j]==1 && atl[i][j]==1)
            ans.push_back({i,j});
        }
      }
      return ans;
    }
  void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>& sea)
  {
    if(i<0||j<0||i>m-1||j>n-1||sea[i][j]==1) return;
    sea[i][j]=1;
    for(int d=0;d<4;d++){
      int r=i+dir[d];
      int c=j+dir[d+1];
      if(r<0||c<0||r>m-1||c>n-1) continue;
      if(heights[r][c]>=heights[i][j])
        dfs(r,c,heights,sea);
    }
  }
    void dfs1(int r,int c,vector<vector<int>>&heights,vector<vector<int>>&sea){
      if(r<0||r>m-1||c<0||c>n-1||sea[r][c]==1) return;
    sea[r][c]=1;
    for(int i=0;i<4;i++){
      int rn=r+dir[i];
      int cn=c+dir[i+1];
      if(heights[rn][cn]>=heights[r][c]) 
      dfs(rn,cn,heights,sea);
    }
  }
};