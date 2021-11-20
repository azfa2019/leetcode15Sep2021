class Solution {
  public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size(),n=matrix[0].size();
    unordered_set<int>col,row;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(matrix[i][j]==0){
          col.insert(j);
          row.insert(i);
        }
      }
    }
    for(int c:col){
      for(int i=0;i<m;i++) {
        matrix[i][c]=0;
      }
    }
    for(int r:row){
      for(int j=0;j<n;j++) {
        matrix[r][j]=0;
      }
    }
  }
};
