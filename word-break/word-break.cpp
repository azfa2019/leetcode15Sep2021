class Solution {
  public:
  bool wordBreak(string s, vector<string>& wordDict) {
      int n=s.size();
      unordered_set<string>st;
      for(auto s:wordDict) st.insert(s);
      s="#"+s;
      vector<bool>dp(n+1,false);
      dp[0]=true;
      for(int j=1;j<=n;j++){
          for(int i=1;i<=j;i++){
              string cur=s.substr(i,j-i+1);
              if(st.find(cur)!=st.end() && dp[i-1]==true) dp[j]=true;
          }
      }
      return dp[n];
  }
};
//n=1
// j=1