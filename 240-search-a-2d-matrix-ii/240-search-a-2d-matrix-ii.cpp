class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            int t=matrix[i][j];
            if(t==target) return true;
            else if(t>target) j--;
            else i++;
        }
        return false;
    }
};