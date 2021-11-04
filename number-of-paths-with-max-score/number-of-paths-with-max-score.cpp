typedef long long ll;
class Solution {
  ll M=1e9+7;
  public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    int n=board.size();
    vector<vector<ll>>dp (n,vector<ll>(n,-1));
    vector<vector<ll>>dp1(n,vector<ll>(n,0));
    board[0][0]='0';
    for(int i=n-1;i>=0;i--){
      for(int j=n-1;j>=0;j--){
        if(i==n-1 && j==n-1){
          dp[i][j]=0;
          dp1[i][j]=1;
          continue;
        }
        if(board[i][j]=='X') continue;
        int right=-1,down=-1,diag=-1;
        if(j+1<n) right=dp[i][j+1];
        if(i+1<n) down=dp[i+1][j];
        if(i+1<n && j+1<n) diag=dp[i+1][j+1];
        dp[i][j]=max(right,max(down,diag));
        if(dp[i][j]==-1) continue;
        
        if(j+1<n && right!=-1 && dp[i][j]==right)        dp1[i][j]= (dp1[i][j]+  dp1[i][j+1])%M;
        if(i+1<n &&  down!=-1 &&dp[i][j]==down)          dp1[i][j]= (dp1[i][j]+  dp1[i+1][j])%M;
        if(i+1<n && j+1<n && diag!=-1 && dp[i][j]==diag) dp1[i][j]= (dp1[i][j]+dp1[i+1][j+1])%M;
        
        dp[i][j]=(dp[i][j]+board[i][j]-'0')%M;
        
      }
    }

    return {dp[0][0]==-1l?0:(int)dp[0][0],(int)dp1[0][0]};
  }
};
//dp[i][j]=dp[i+1][j]+board[i][j], dp[i][j+1]+board[i][j], dp[i+1][j+1]+board[i][j]
//dp1[i][j]=

// e 2 3
// 2 x 2
// 1 2 s