class Solution {
public:
    int minTotalDistance(vector<vector<int>>& g) {
        vector<int>row,col;
        for(int i=0;i<g.size();i++)
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1) row.push_back(i),col.push_back(j);
            }
        return helper(row)+helper(col);
    }
    int helper(vector<int>v){
        int res=0;
        sort(v.begin(),v.end());
        int i=0,j=v.size()-1;
        while(i<j) res+=v[j--]-v[i++];
        return res;
    }
};