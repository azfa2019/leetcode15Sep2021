class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int rs=0,re=m-1,cs=0,ce=n-1;
        vector<int>ans;
        while(rs<re && cs<ce){
            for(int i=cs;i<=ce-1;i++) ans.push_back(matrix[rs][i]);
            for(int i=rs;i<=re-1;i++) ans.push_back(matrix[i][ce]);
            for(int i=ce;i>=cs+1;i--) ans.push_back(matrix[re][i]);
            for(int i=re;i>=rs+1;i--) ans.push_back(matrix[i][cs]);
            rs++,re--,cs++,ce--;
        }
        //cout<<cs<<ce<<rs<<re<<endl;
        if(cs>ce && rs>re) return ans;
        else if(rs<=re && cs==ce) for(int i=rs;i<=re;i++) ans.push_back(matrix[i][cs]);
        else if(rs==re && cs<=ce) for(int i=cs;i<=ce;i++) ans.push_back(matrix[rs][i]);
        return ans;
    }
};
//2 5 9
//8 4 9
//0-1 9
//1 2 3
//rs=0, re=2, cs=0, ce=1
//rs=1,re=1,cs=1,ce=0, more rows than column