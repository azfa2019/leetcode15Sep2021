class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size(),m=o[0].size();
        vector<vector<int>>f(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(o[i][j]==0){
                    if(i==0&&j==0) f[i][j]=1;
                    else{
                        if(i) f[i][j]+=f[i-1][j];
                        if(j) f[i][j]+=f[i][j-1];
                    }
                }
        return f[n-1][m-1];
    }
};