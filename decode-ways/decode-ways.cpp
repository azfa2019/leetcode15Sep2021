class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        s="#"+s;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=(valid(s.substr(1,1))?1:0);
        for(int i=2;i<=n;i++)
            dp[i]=(valid(s.substr(i-1,2))?dp[i-2]:0)+
                        (valid(s.substr(i,1))?dp[i-1]:0);
        return dp[n];
    }
    bool valid(string s){
        if(s[0]=='0') return false;
        if(s.size()==1) return (s[0]>='1' && s[0]<='9');
        if(s.size()==2) return (s<="26" && s>="10");
        return true;
    }
};
//  2    2    6
//  i-2  i-1  i
//  # 1.  2
//  0     i
// 
// 