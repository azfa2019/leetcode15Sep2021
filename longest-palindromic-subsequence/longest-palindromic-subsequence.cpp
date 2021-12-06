class Solution {
  //int dp[1001][1001];
  public:
  int longestPalindromeSubseq(string s) {
      int n=s.size();
      vector<vector<int>>dp(n,vector<int>(n,0));
      for(int i=0;i<n;i++) dp[i][i]=1;
      for(int len=2;len<=n;len++){
          for(int i=0;i+len-1<n;i++){
              int j=i+len-1;
              if(s[i]==s[j]) dp[i][j]=(i+1>j-1?0:dp[i+1][j-1])+2;
              else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
          }
      }
      return dp[0][n-1];
  }
};
// b b b a b c d
//.    i     j 
//len=j-i+1, j=i+len-1
//if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
// else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
//  baaa c
//  i    j
//  b aaab
//  i    j