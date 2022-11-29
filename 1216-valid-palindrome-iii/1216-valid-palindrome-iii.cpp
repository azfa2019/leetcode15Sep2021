class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int j=0;j<n;j++)
            for(int i=j-1;i>=0;i--){
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        return n-dp[0][n-1]<=k;
    }
};