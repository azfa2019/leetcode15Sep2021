class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j]) dp[i][j]=2+(i+1>j-1?0:dp[i+1][j-1]);
                else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};