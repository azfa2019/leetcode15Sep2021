class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m=o.size(),n=o[0].size();
        vector<vector<int>>f(m,vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(o[i][j]==0){
                    if(i==0 && j==0) f[i][j]=1;
                    else {
                        if(i) f[i][j]+=f[i-1][j];
                        if(j) f[i][j]+=f[i][j-1];
                    }
                }
            }
        return f[m-1][n-1];
    }
};