class Solution {
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        unordered_set<int>rset,cset;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) {
                    rset.insert(i);
                    cset.insert(j);
                }
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(rset.find(i)!=rset.end() || cset.find(j)!=cset.end() )
                    matrix[i][j]=0;
            }

    }
};