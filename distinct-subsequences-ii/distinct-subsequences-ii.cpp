class Solution {
  long long dp[2001];
  long M=1e9+7;
  public:
  int distinctSubseqII(string s) {
    //dp[i]: # of subseq using s[1:i]
    // a b x
    // dp[i] = 2*dp[i-1]+1
    dp[0]=0;
    int n=s.size();
    s="#"+s;
    //unordered_set<char>set;
    //for(char c:s) set.insert(c);
    //dp[1]=set.size()-1;
    for(int i=1;i<=n;i++){
      dp[i]+=2L*dp[i-1]%M+1L;
      dp[i]%=M;
      //cout<<"dp[i]="<<dp[i]<<endl;
      for(int j=i-1;j>=1;j--){
        if(s[j]==s[i]) {
          dp[i]-=(dp[j-1]%M+1L);
          dp[i]+=M;
          //if(dp[i]<0) cout<<"<0! "<<dp[i]<<","<<dp[j-1]<<endl;
          break;
        }
      }
      dp[i]%=M;
    }
    return dp[n]%M;
  }
};
// a b     a   a count[a]=2, if s[i]==s[i-1], subtract dp[i-2]
//.  i-2  i-1  i
// a b a   c   a count[a]=2, if s[i]==s[j], subtract dp[i-1]
// a a: 2, dp[2]=2
// a a a: i=3, j=1: dp[3]=7, j=1: 7-1=6; j=2, 6-dp[1]=