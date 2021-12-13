class Solution {
  public:
  void setZeroes(vector<vector<int>>& matrix) {
      int m=matrix.size(),n=matrix[0].size();
      unordered_set<int>setRow;
      unordered_set<int>setCol;
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(matrix[i][j]==0) setRow.insert(i),setCol.insert(j);
          }
      }
      
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(setRow.find(i)!=setRow.end()||setCol.find(j)!=setCol.end()) matrix[i][j]=0;
          }
      }
      
  }
};