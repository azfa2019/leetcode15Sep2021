class Solution {
  long M=1e9+7;
  public:
  int numberOfArrays(string s, int k) {
    //dp[i]: # of ways up to s[i]
    //dp[i-1]+1 s[i] if s[i]<=k & >=1
    //dp[i-2]+1 s[i-1:i] if s[i-1:i]<=k && >=1
    //if(s[i]=='0') continue;
    int n=s.size();
    s="#"+s;
    vector<int>dp(n+1,0);
    dp[0]=1;//how many arrays when there is 0 number
    for(int i=1;i<=n;i++){
      long x=0;
      for(int j=0;j<=9;j++){
        if(i-j<=0) break;
        x=x+pow(10,j)*(s[i-j]-'0');
        if(s[i-j]=='0') continue;
        if(x>k) break;
        //if(x==0) continue;
        dp[i]=(dp[i]+dp[i-j-1])%M;
      }
    }
    return dp[n];
  }
};
// 0 1 3 1 7
//     x   i i=4, j=2, i-j-1=1