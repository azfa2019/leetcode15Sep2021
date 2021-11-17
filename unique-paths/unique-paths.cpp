class Solution {
public:
    int uniquePaths(int m, int n) {
      long ans=1;
      for(int i=1;i<=m-1;i++){
        ans=ans*(n+i-1)/i;
      }
      return ans;
    }
};
// m+n-2
// m-1
// (m+n-2)!/(n-1)!(m-1)!
// (m+n-2) (m+n-3) ... (n+1)(n)(n-1)(n-2).../(n-1)!(m-1)!
// (m+n-2)(m+n-3) ...(n+1)n/(m-1)!