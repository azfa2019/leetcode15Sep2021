class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>cntcol(m),cntrow(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]) cntcol[j]++,cntrow[i]++;
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j] && cntcol[j]==1&&cntrow[i]==1) res++;
        return res;
    }
};