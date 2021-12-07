class Solution {
    public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,1));
        int maxLen=1;
        string ans=s.substr(0,1);
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]) {
                dp[i][i+1]=2;
                maxLen=2;
                ans=s.substr(i,2);
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]==j-1-i) 
                    dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                if(dp[i][j]>maxLen){
                    maxLen=dp[i][j];
                    ans=s.substr(i,maxLen);
                }
            }
        }
        return ans;
    }
};
// x x x x x x
//   i.    j