class Solution {
  int M=1e9+7;
public:
    int findDerangement(int n) {
      vector<long>dp(n+1,0); //dp[i]: # of derangements ending with number i
      if(n==1) return 0;
      if(n==2) return 1;
      long a=0;
      long b=1;
      long c;
      for(int i=3;i<=n;i++){
        c=(i-1)*(a%M+b%M);
        c=c%M;
        a=b;
        b=c;
      }
      return c;
    }
};