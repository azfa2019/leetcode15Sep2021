class Solution {
    int dp[100001];
public:
    bool winnerSquareGame(int n) {
        for(int i=1;i<=n;i++) dp[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==0){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};