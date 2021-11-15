class Solution {
public:
    int countSubstrings(string s) {
      int n=s.size();
      s="#"+s;
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      for(int i=1;i<=n;i++){
        dp[1][i]=1;
        dp[0][i]=1;
      }
      int count=0;
      for(int len=2;len<=n;len++){
        for(int j=len;j<=n;j++){
          if(s[j]==s[j-len+1]){
            dp[len][j]=dp[len-2][j-1];
          }
          count+=dp[len][j];
        }
      }
      return count+n;
    }
};
// daac
//012345
//dp[4][4]=dp[2][3]
//dp[len][j]=dp[len-2][j-1] if s[j]==s[j-len+1]