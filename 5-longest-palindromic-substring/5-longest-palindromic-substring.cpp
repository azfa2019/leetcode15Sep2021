class Solution {
    public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        int maxLen=0,start=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j])
                    dp[i][j]=(i+1<j-1?dp[i+1][j-1]:true);
                if(j-i+1>maxLen && dp[i][j]){
                    maxLen=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
// a a
// i i+1 dp[i+1][i]
// 
// 
// 
// 