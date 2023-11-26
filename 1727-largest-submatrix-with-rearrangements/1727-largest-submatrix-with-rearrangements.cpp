class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        int h=m.size(),w=m[0].size();
        vector<vector<int>>up(h,vector<int>(w,0));
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(m[i][j]) up[i][j]=(i==0?0:up[i-1][j])+1;
        int res=0;
        for(int i=0;i<h;i++){
            vector<int>buf;
            for(int j=0;j<w;j++)
                buf.push_back(up[i][j]);
            sort(buf.begin(),buf.end());
            for(int j=0;j<w;j++) res=max(res,buf[j]*(w-j));        
        }
        return res;
    }
};