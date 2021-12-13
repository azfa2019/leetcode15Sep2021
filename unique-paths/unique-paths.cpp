class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans=1;
        for(int i=1;i<n;i++){
            ans=ans*(m-1+i)/i;
        }
        return ans;
    }
};
// m+n-2
// m-1
// (m+n-2)!/(m-1)!/(n-1)!
// (m+n-2)!=(m-1+n-1)(m-2+n-1) ...(1+n-1){(n-1)(n-2)...1}
// (m+n-2)! /(m-1)!(n-1)!
// (m+n-2) (m+n-3) m (m-1)!/ (m-1)! (n-1)!
// ---------n-1------