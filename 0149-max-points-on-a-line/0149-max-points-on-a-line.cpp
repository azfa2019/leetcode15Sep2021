class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;
        int res=0;
        for(auto& p:points){
            int ss=0,vs=0;
            unordered_map<LD,int>cnt;
            for(auto& q:points){
                if(q==p) ss++;
                else if(q[0]==p[0]) vs++;
                else{
                    LD k=(LD)(q[1]-p[1])/(q[0]-p[0]);
                    cnt[k]++;
                }
            }
            int c=vs;
            for(auto&[k,v]:cnt) c=max(c,v);
            res=max(res,c+ss);
        }
        return res;
    }
};