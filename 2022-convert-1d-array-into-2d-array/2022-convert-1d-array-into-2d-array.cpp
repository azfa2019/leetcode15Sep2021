class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if(o.size()!=n*m) return {};
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans[i][j]=o[i*n+j];
        }
        return ans;
    }
};