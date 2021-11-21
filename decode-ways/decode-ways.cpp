class Solution {
  public:
  int numDecodings(string s) {
    int n=s.size();
    s="#"+s;
    vector<int>dp(n+1,0);
    dp[0]=1;
    string first=s.substr(1,1);
    if(valid(first)) dp[1]=1;
    for(int i=2;i<=n;i++){
      string s1=s.substr(i,1);
      if(valid(s1)) dp[i]+=dp[i-1];
      string s2=s.substr(i-1,2);
      // 1110     6
      //.   i-1   i
      if(valid(s2)) dp[i]+=dp[i-2];
    }
    return dp[n];
  }
  bool valid(string s){
    int num=stoi(s);
    if(s.size()==1) {
      if(num<1 || num>9) return false;;
    }
    if(s.size()==2) {
      if(s[0]=='0') return false;
      if(num<1 || num>26) return false;
    }
    return true;
  }
};
//dp[i]=dp[i-1]+dp[i-2]