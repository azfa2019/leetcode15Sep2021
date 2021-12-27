class Solution {
    public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        int maxLen=1;
        int start=0;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(i+1==j) dp[i][j]=true;
                    else if(i+1<j) dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]==true && j-i+1>maxLen) {
                    maxLen=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};