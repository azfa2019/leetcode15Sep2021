class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(i==j) sum+=mat[i][j];
                if(j+i==n-1) sum+=mat[i][j];
                if(i==j && i+j==n-1) sum-=mat[i][j];
            }
        return sum;
    }
};