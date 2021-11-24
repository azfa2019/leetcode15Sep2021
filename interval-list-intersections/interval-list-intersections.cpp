class Solution {
  public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>&B) {
    int m=A.size(),n=B.size();
    int i=0,j=0;
    vector<vector<int>>ans;
    while(i<m && j<n){
      if(A[i][1]>=B[j][0]&&A[i][1]<=B[j][1] || B[j][1]>=A[i][0]&&B[j][1]<=A[i][1]) ans.push_back({max(B[j][0],A[i][0]),min(B[j][1],A[i][1])});
      if(B[j][1]>A[i][1]) i++;
      else if(B[j][1]<A[i][1]) j++;
      else i++,j++;
    }
    return ans;
  }
};
// 1      7
//0. 2 3. 7
//[0,2],[5,   10],[13,23],[24, 25]
//[1,    5],[8, 12],[15,   24],[25,26]