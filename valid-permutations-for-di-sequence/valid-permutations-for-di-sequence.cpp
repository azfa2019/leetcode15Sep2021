typedef long long ll;
class Solution {
  ll dp[201][201];
  ll M=1e9+7;
  public:
  int numPermsDISequence(string s) {
    int n=s.size();
    s="#"+s;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
      for(int j=0;j<=i;j++){
        if(s[i]=='I'){
          for(int k=0;k<=j-1;k++){
            dp[i][j]+=dp[i-1][k];
            dp[i][j]%=M;
          }
        }else{
          for(int k=j;k<=i-1;k++){
            dp[i][j]+=dp[i-1][k];
            dp[i][j]%=M;
          }
        }
      }
    }
    ll ans=0;
    for(int i=0;i<=n;i++) {
      ans+=dp[n][i];
      ans%=M;
    }
    return ans;
  }
};
