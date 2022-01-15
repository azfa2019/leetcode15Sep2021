class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        s='#'+s;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=valid(s.substr(1,1))?1:0;
        for(int i=2;i<=n;i++){
            if(valid(s.substr(i,1))) dp[i]+=dp[i-1];
            if(valid(s.substr(i-1,2))) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
    bool valid(string s){
        if(s.size()==1){
            return (s>="1" && s<="9");
        }
        return (s>="10" && s<="26");
    }
};
// 111     0     6
//   i-2   i-1   i
// 
// 
// 
// 