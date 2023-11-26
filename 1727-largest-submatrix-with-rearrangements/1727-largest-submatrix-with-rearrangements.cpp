class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        int h=m.size(),w=m[0].size();
        vector<vector<int>>up(h,vector<int>(w,0));
        for(int i=1;i<h;i++)
            for(int j=0;j<w;j++)
                if(m[i][j]) m[i][j]+=m[i-1][j];
        int res=0;
        for(int i=0;i<h;i++){
            sort(m[i].begin(),m[i].end());
            
            for(int j=w-1;j>=0;j--) {
                int height=m[i][j];
                res=max(res,height*(w-j));   
            }
        }
        return res;
    }
};