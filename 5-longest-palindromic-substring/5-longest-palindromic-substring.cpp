class Solution {
    public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        int start=0,maxLen=1;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j])
                    dp[i][j]=(i+1<=j-1?dp[i+1][j-1]:true);
                if(maxLen<j-i+1 && dp[i][j]){
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