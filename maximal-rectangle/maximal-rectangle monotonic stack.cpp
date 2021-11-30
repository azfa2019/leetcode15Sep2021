class Solution {
  int m,n;
  public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size()==0) return 0;
    m=matrix.size(),n=matrix[0].size();
    vector<vector<int>>grid(m,vector<int>(n));
    buildGrid(matrix,grid);
    int ans=0;
    for(int i=0;i<m;i++){
      ans=max(ans,maxArea(grid,i));
    }
    return ans;
  }
  void buildGrid(vector<vector<char>>& matrix,vector<vector<int>>&grid){
    for(int j=0;j<n;j++) grid[0][j]=matrix[0][j]=='1'?1:0;
    for(int i=1;i<m;i++){
      for(int j=0;j<n;j++){
        grid[i][j]+=matrix[i][j]=='1'?grid[i-1][j]+1:0;
      }
    }
  }
  int maxArea(vector<vector<int>>&grid,int bottom){
    int ans=0;
    stack<int>stack;
    stack.push(-1);
    for(int i=0;i<n;i++){
      while(stack.top()!=-1 && grid[bottom][stack.top()]>=grid[bottom][i]){
        int tmp=grid[bottom][stack.top()]; stack.pop();
        ans=max(ans,tmp*(i-stack.top()-1));
      }
      stack.push(i);
    }
    while(stack.top()!=-1){
        int tmp=grid[bottom][stack.top()]; stack.pop();
        ans=max(ans,tmp*(n-stack.top()-1));
    }
    return ans;
  }
};
