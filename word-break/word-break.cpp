class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        s="#"+s;
        vector<int>dp(n+1,false);
        dp[0]=true;
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                string word=s.substr(j,i-j+1);
                if(dp[j-1] && st.find(word)!=st.end()) dp[i]=true;
            }
        }
        return dp[n];
    }
};
// dp[i] = dp[j] if s.substr(j+1,i-j) in wordDict
//  x x x x
//    j.  i
// 
// 
// 