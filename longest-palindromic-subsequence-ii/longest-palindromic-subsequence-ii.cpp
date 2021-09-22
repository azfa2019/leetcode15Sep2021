class Solution {
  public:
  int dp[250][250][26];
  int longestPalindromeSubseq(string s) {
    int n=s.size();
    for(int i=0;i+1<n;i++) 
      if(s[i]==s[i+1]) dp[i][i+1][s[i]-'a']=2;
    for(int len=3;len<=n;len++)
      for(int i=0;i+len-1<n;i++){
        int j=i+len-1;
        int left=s[i]-'a';
        int right=s[j]-'a';
        if(s[i]==s[j]){ //left==right
          for(int k=0;k<26;k++)
            if(left!=k) dp[i][j][left]=max(dp[i][j][left],dp[i+1][j-1][k]+2);
          for(int k=0;k<26;k++)
            if(left!=k) dp[i][j][k]=dp[i+1][j-1][k];
        }else{
          dp[i][j][left]=dp[i][j-1][left];
          dp[i][j][right]=dp[i+1][j][right];
          for(int k=0;k<26;k++) 
            if(k!=left && k!=right) dp[i][j][k]=dp[i+1][j-1][k];
        }
      }
    int ans=0;
    for(int k=0;k<26;k++)
      ans=max(ans,dp[0][n-1][k]);
    return ans;
  }
};
//bb aba b: 2
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