class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=m*n-1;
        while(l<r){
            int mid=l+r>>1;
            int u=mid/n,v=mid%n;
            if(matrix[u][v]<target) l=mid+1;
            else r=mid;
        }
        return matrix[l/n][l%n]==target;
    }
};
