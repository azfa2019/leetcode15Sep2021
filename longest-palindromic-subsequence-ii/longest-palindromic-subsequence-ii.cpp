class Solution {
  public:
  int dp[250][250][26];
  int longestPalindromeSubseq(string s) {
   int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));// dp[i][j]: max # of palindromic subsequence
    vector<vector<char>>edge(n,vector<char>(n));// edge[i][j]: edge char of palindromic subsequence in the range of s[i] to s[j]
    for(int i=0;i<n-1;i++) 
      if(s[i]==s[i+1]) dp[i][i+1]=2,edge[i][i+1]=s[i];
    for(int len=3;len<=n;len++){
      for(int i=0;i+len-1<n;i++){
        int j=i+len-1;
        if(s[i]==s[j]&&s[i]!=edge[i+1][j-1]) dp[i][j]=dp[i+1][j-1]+2,edge[i][j]=s[i];
        else if(dp[i][j-1]>dp[i+1][j]) dp[i][j]=dp[i][j-1],edge[i][j]=edge[i][j-1];
        else dp[i][j]=dp[i+1][j],edge[i][j]=edge[i+1][j];
      }
    }
    return dp[0][n-1];
  }
};
//b caae b: dp[1][4][a]=2, dp[2][3][a]=2, i=1, j=4, s[i]!=s[j]
//0 1234 5
//b babab: 3, if s[i]==s[j] dp[i][j]=dp[i+1][j-1]+1
//b aabab: 3, if s[i]==s[j] dp[i][j]=dp[i+1][j-1]+1

//bc abc b: 1
//b cabcb: 1, iterate k:i+1...j-1, if equal, dp[i][j]=2

//bb ccb b: 2
//b babbb: 1, iterate k:i+1...j-1, if equal, dp[i][j]=2
// aa
// a fabbae a
//abc
//  fabae 
// a fabae a