class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>f(m,vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(!i || !j) f[i][j]=1;
                else{
                    f[i][j]+=f[i][j-1];
                    f[i][j]+=f[i-1][j];
                }
            }
        return f[m-1][n-1];
    }
};