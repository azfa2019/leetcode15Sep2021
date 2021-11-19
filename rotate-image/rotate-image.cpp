class Solution {
  public:
  void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int l=0;l<n/2;l++){
      int s=l+1,e=n-1-l;
      int tmp;
      for(int i=s;i<=e;i++){
        tmp=matrix[l][i];
        matrix[l][i]=matrix[n-1-i][l];
        matrix[n-1-i][l]=matrix[n-1-l][n-1-i];
        matrix[n-1-l][n-1-i]=matrix[i][n-1-l];
        matrix[i][n-1-l]=tmp;
      }
    }
  }
};
// x 15 13 2 5 x  l=1, 
//1 4 8
//6 5 3
//7 2 9