class Solution {
  public:
  string longestPalindrome(string s) {
    int n=s.size();
    s="#"+s;
    vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
    string ans=s.substr(1,1);
    int maxLen=1;
    for(int i=1;i<=n;i++) dp[i][i]=true;
    for(int j=1;j<=n;j++){
      for(int i=1;i<=j;i++){
        //cout<<i<<","<<j<<endl;
        if(s[i]==s[j]) dp[i][j]=(i+1>j-1)?true:dp[i+1][j-1];
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
//abcbd
//0, 4
//if even: cccccc 
//len=6, left=2, starting = 2-(6-1)/2=0
//if odd: ccccc, left=2, len=5, starting=0, len=5, starting=2-(5-1)/2=0
