class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans=1;
        for(int j=1;j<=n-1;j++){
            ans=ans*(m-1+j)/j;
        }
        return ans;
    }
};
// (m-1+n-1)!/ (m-1)!
// (m-1+n-1) (m-1+n-2) (m-1+n-3) ...(m-1+1) (m-1)!
//  (m-1)! (n-1)!
// 2! * 6!=6*5*4*3*2*2=1440
// 8!=8*7*6!=56
//2+6 * 2+5 * 2+4 * 2+3