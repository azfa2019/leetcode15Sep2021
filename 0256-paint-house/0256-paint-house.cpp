class Solution {
public:
    int minCost(vector<vector<int>>& c) {
        int n=c.size();
        vector<vector<int>>f(n,vector<int>(3));
        for(int j=0;j<3;j++)
            f[0][j]=c[0][j];
        for(int i=1;i<n;i++){
            f[i][0]=c[i][0]+min(f[i-1][1],f[i-1][2]);
            f[i][1]=c[i][1]+min(f[i-1][0],f[i-1][2]);
            f[i][2]=c[i][2]+min(f[i-1][0],f[i-1][1]);
        }
        int res=1e9;
        for(int i=0;i<3;i++) res=min(res,f[n-1][i]);
        return res;
    }
};