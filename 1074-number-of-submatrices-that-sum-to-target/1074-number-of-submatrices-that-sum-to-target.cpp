class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& g, int target) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>s(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                s[i][j]=s[i-1][j]+g[i-1][j-1];
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++){
                unordered_map<int,int>cnt;
                cnt[0]++;
                for(int k=1,sum=0;k<=m;k++){
                    sum+=s[j][k]-s[i-1][k];
                    res+=cnt[sum-target];
                    cnt[sum]++;
                }
            }
        return res;
    }
};