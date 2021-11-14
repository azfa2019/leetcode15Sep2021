class Solution {
public:
    int numPermsDISequence(string s) {
      int n=s.size();
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      dp[0][0]=1;
      int M=1e9+7;
      for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
          if(s[i-1]=='D'){
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
      int ans=0;
      for(int j=0;j<=n;j++){
        ans+=dp[n][j];
        ans%=M;
      }
      return ans;
    }
};