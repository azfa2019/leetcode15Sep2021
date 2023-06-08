class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        int res=0;
        for(int i=0,j=n-1;i<m;i++){
            while(j>=0&&g[i][j]<0) j--;
            res+=n-1-j;
        }
        return res;
    }
};