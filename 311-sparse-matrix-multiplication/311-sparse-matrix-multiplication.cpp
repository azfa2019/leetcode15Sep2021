class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>>res(mat1.size(),vector<int>(mat2[0].size()));
        for(int i=0;i<mat1.size();i++){
            for(int k=0;k<mat1[0].size();k++){
                if(mat1[i][k]!=0){
                    for(int j=0;j<mat2[0].size();j++){
                        if(mat2[k][j]!=0){
                            res[i][j]+=mat1[i][k]*mat2[k][j];
                        }
                    }
                }
            }
        }
        return res;
    }
};