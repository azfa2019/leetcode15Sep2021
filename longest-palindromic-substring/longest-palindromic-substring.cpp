class Solution {
  bool dp[1001][1001];
  public:
  string longestPalindrome(string s) {
    int n=s.size();
    s="#"+s;
    int maxLen=1;
    string ans=s.substr(1,1);
    for(int i=1;i<=n;i++) dp[i][i]=true;
    for(int len=2;len<=n;len++){
      for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        if(s[i]==s[j]) dp[i][j]=i+1==j?true:dp[i+1][j-1];
        else dp[i][j]=false;
        if(dp[i][j]==true && j-i+1>maxLen){
          maxLen=j-i+1;
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
