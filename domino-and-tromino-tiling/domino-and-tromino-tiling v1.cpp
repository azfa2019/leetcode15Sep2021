class Solution {
    long long M=1e9+7;
public:
    int numTilings(int n) {
        vector<vector<long>>dp(n+1,vector<long>(2,0));
        dp[0][0]=1;
        dp[1][0]=1;
        for(int i=2;i<=n;i++){
            dp[i][0]=(dp[i-1][0]+dp[i-2][0]+2*dp[i-1][1])%M;
            dp[i][1]=(dp[i-2][0]+dp[i-1][1])%M;
        }
        return dp[n][0];
    }
};
//.      i
// o o o x 
// o o o x  
//.        i
// o o o x x
// o o o y y
//.        i
// o o o x x
// o o o o x
//.        i
// o o o o x
// o o o x x
//.      i
// o o x x 
// o o x 
//.      i
// o o x x 
// o o o 
//dp[i][0]=dp[i-1][0]+dp[i-2][0]+2*dp[i-1][1]
//dp[i][1]=dp[i-2][0]+dp[i-1][1]
