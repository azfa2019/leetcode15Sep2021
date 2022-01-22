class Solution {
    int dp[100001];
public:
    bool winnerSquareGame(int n) {
       for(int i=1;i<=n;i++) dp[i]=-1;
        return canwin(n);
    }
    bool canwin(int n){
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(!canwin(n-i*i)) {
                dp[n]=1;
                return dp[n];
            }
        }
        dp[n]=0;
        return dp[n];
    }
};