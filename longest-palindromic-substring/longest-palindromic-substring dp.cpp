class Solution {
  public:
  string longestPalindrome(string s) {
    int n=s.size();
    s="#"+s;
    vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
    //dp[0][0]=;
    string ans=s.substr(1,1);
    int maxLen=1;
    for(int i=1;i<=n;i++) dp[i][i]=true;
    for(int len=2;len<=n;len++){
      for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        if(s[i]==s[j]) dp[i][j]=(i+1==j)?true:dp[i+1][j-1];
        if(dp[i][j]==true && maxLen<len){
          maxLen=len;
          ans=s.substr(i,maxLen);
        }
      }
    }
    return ans;
  }
};
// 0 1 2 3 4
// b a b b a c
//   i     j
