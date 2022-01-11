class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>ans;
        int rs=0,re=m-1,cs=0,ce=n-1;
        while(rs<re && cs<ce){
            for(int i=cs;i<=ce-1;i++) ans.push_back(matrix[rs][i]);
            for(int j=rs;j<=re-1;j++) ans.push_back(matrix[j][ce]);
            for(int k=ce;k>=cs+1;k--) ans.push_back(matrix[re][k]);
            for(int l=re;l>=rs+1;l--) ans.push_back(matrix[l][cs]);
            rs++,re--,cs++,ce--;
        }
        if(rs==re) for(int i=cs;i<=ce;i++) ans.push_back(matrix[rs][i]);
        else if(cs==ce) for(int i=rs;i<=re;i++) ans.push_back(matrix[i][cs]);
        return ans;
    }
};