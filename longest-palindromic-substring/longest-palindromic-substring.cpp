class Solution {
    public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        int maxLen=0;
        string ans;
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j]){
                    if(i+1==j) dp[i][j]=true;
                    else if(i+1<j) dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]==true && j-i+1>maxLen){
                    maxLen=j-i+1;
                    ans=s.substr(i,maxLen);
                }
            }
        }
        return ans;
    }
};
// babad
// i=n-1, dp[n][j]
// i=n-2, j=n-2, j=n-1, dp[n-1][n-1]
// i+1, j-1
// i=0
//i=n-1