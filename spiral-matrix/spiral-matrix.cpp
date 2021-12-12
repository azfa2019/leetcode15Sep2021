class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int layer=min(m/2,n/2);
        vector<int>ans;
        int rs=0,cs=0,re=m-1,ce=n-1;
        while(rs<re && cs<ce){
            for(int j=cs;j<ce;j++) 
                ans.push_back(matrix[rs][j]);
            for(int i=rs;i<re;i++)
                ans.push_back(matrix[i][ce]);
            for(int j=ce;j>cs;j--) 
                ans.push_back(matrix[re][j]);
            for(int i=re;i>rs;i--)
                ans.push_back(matrix[i][cs]);
            rs++,re--;
            cs++,ce--;
        }
        if(rs==re){
            for(int j=cs;j<=ce;j++) ans.push_back(matrix[rs][j]);
        } else if(cs==ce){
            for(int i=rs;i<=re;i++) ans.push_back(matrix[i][cs]);
        } 
        return ans;
    }
};
// if m<n, last are rows
//m=4,n=5
// xxxxx
// xxxxx
// xxxxx
// xxxxx

//if m>n, last are columns
// xxxx
// xxxx
// xxxx
// xxxx
// xxxx