class Solution {
  public:
  string longestPalindrome(string s) {
      int n=s.size();
      vector<vector<bool>>dp(n,vector<bool>(n,false));
      string ans=s.substr(0,1);
      int maxLen=1;
      for(int i=0;i<n;i++) dp[i][i]=true;
      for(int len=2;len<=n;len++){
          for(int i=0;i+len-1<n;i++){
              int j=i+len-1;
              if(s[i]==s[j]) dp[i][j]=i+1>j-1?true:dp[i+1][j-1];
              if(dp[i][j]==true && j-i+1>maxLen){
                  maxLen=j-i+1;
                  ans=s.substr(i,maxLen);
              }
          }
      }
      return ans;
  }
};
//abcbd
//0, 4
//if even: cccccc 
//len=6, left=2, starting = 2-(6-1)/2=0
//if odd: ccccc, left=2, len=5, starting=0, len=5, starting=2-(5-1)/2=0
// abbc b
//  i   j
//if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]