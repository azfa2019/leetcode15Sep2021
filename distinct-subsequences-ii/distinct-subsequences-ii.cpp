class Solution {
  long long dp[2001];
  long M=1e9+7;
  public:
  int distinctSubseqII(string s) {
    //dp[i]: # of subseq using s[1:i] including empty case
    // a b x
    // dp[i] = 2*dp[i-1]
    dp[0]=1;
    int n=s.size();
    s="#"+s;
    vector<int>last(26,0);
    for(int i=1;i<=n;i++){
      int j=last[s[i]-'a'];
      dp[i]=dp[i-1]*2-(j>=1?dp[j-1]:0);
      dp[i]+=M;
      dp[i]%=M;
      last[s[i]-'a']=i;
    }
    return dp[n]-1;
  }
};
// a b     a   a count[a]=2, if s[i]==s[i-1], subtract dp[i-2]
//.  i-2  i-1  i
// a b a   c   a count[a]=2, if s[i]==s[j], subtract dp[i-1]
// a a: 2, dp[2]=2
// a a a: i=3, j=1: dp[3]=7, j=1: 7-1=6; j=2, 6-dp[1]=