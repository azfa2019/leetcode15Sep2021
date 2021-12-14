class Solution {
    public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        s="#"+s;
        dp[0]=1;
        dp[1]=valid(s.substr(1,1))?1:0;
        for(int i=2;i<=n;i++){
            string cur1=s.substr(i,1);
            string cur2=s.substr(i-1,2);
            dp[i]=(valid(cur2)?dp[i-2]:0)+(valid(cur1)?dp[i-1]:0);
        }
        return dp[n];
    }
    bool valid(string s){
        if(s[0]=='0') return false;
        if(s.size()==1 && (s<"1"||s>"9")) return false;
        if(s.size()==2 &&(s<"10"||s>"26")) return false;
        return true;
    }
};
// 2   2    6
// i-2 i-1  i