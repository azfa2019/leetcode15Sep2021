class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int>sum(n+1);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i-1]-'0';
        int res=2e9;
        for(int i=1;i<=n;i++)
            res=min(res,sum[i]+(n-i)-(sum[n]-sum[i-1]));
        return res;
    }
};