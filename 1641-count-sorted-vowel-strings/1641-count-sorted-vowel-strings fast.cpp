class Solution {
    
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=1;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
            dp[i][1]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
            dp[i][2]=dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
            dp[i][3]=dp[i-1][3]+dp[i-1][4];
            dp[i][4]=dp[i-1][4];
        }
        return dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+ dp[n-1][3]+dp[n-1][4];
    }
};
