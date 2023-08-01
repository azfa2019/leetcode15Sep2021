class Solution {
public:
    vector<long long> minimumCosts(vector<int>& re, vector<int>& ex, int c) {
        typedef long long LL;
        int n=re.size();
        const LL INF=1e15;
        vector<vector<LL>>f(n+1,vector<LL>(2,INF));
        f[0][0]=0;
        f[0][1]=c;
        vector<LL>res(n);
        for(int i=1;i<=n;i++){
            f[i][0]=min(f[i][0],f[i-1][0]+re[i-1]);
            f[i][0]=min(f[i][0],f[i-1][1]+ex[i-1]);
            f[i][1]=min(f[i][1],f[i-1][0]+re[i-1]+c);
            f[i][1]=min(f[i][1],f[i-1][1]+ex[i-1]);
            res[i-1]=min(f[i][0],f[i][1]);
        }
        return res;
    }
};