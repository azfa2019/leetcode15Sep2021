class Solution {
public:
    int numWays(int n, int k) {
      //the last two colors can be same or different
      // xx 
      // xy
      //same[i]=diff[i-1]
      //diff[i]=same[i-1]*(k-1)+diff[i-1]*(k-1)
      if(n==0) return 0;
      if(n==1) return k;
      int diff=k*(k-1);
      int same=k;
      for(int i=3;i<=n;i++){
        int sameTmp=same,diffTmp=diff;
        same=diffTmp;
        diff=sameTmp*(k-1)+diffTmp*(k-1);
      }
      return same+diff;
    }
};