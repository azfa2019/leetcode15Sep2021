class Solution {
  public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int n=s.size();
    s="#"+s;
    vector<bool>dp(n+1,false);
    dp[0]=true;
    unordered_set<string> set(wordDict.begin(),wordDict.end());
    for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
        if(dp[j-1]==true && set.find(s.substr(j,i-j+1))!=set.end()) dp[i]=true;
      }
    }
    return dp[n];
  }
};