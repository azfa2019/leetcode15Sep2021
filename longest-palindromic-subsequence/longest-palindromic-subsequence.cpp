class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n=s.size();
      s="#"+s;
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      //dp[0][0]=0;
      for(int i=1;i<=n;i++) dp[i][i]=1;
      for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
          //len=2, j=i+len-1=i+1
          int j=i+len-1;
          if(s[i]==s[j]) dp[i][j]=(i+1>j-1?0:dp[i+1][j-1])+2;
          else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
      }
      return dp[1][n];
    }
};
//cbbd
//f cbbf d if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2
//bbbd else dp[i][j]=max(dp[i][j-1],dp[i+1][j])
//