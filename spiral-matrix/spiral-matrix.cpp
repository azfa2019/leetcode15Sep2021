class Solution {
  public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size(),n=matrix[0].size();
    int rs=0,cs=0,re=m-1,ce=n-1;
    vector<int>ans;
    while(rs<re&&cs<ce){
      for(int j=cs;j<ce;j++) ans.push_back(matrix[rs][j]);
      for(int i=rs;i<re;i++) ans.push_back(matrix[i][ce]);
      //if(re>rs)
        for(int j=ce;j>cs;j--) ans.push_back(matrix[re][j]);
      //if(ce>cs)
        for(int i=re;i>rs;i--) ans.push_back(matrix[i][cs]);
      rs++,re--;
      cs++,ce--;
    }
    if(rs==re) for(int i=cs;i<=ce;i++) ans.push_back(matrix[rs][i]);
    else if(cs==ce) for(int i=rs;i<=re;i++) ans.push_back(matrix[i][cs]); 
    return ans;
  }
};