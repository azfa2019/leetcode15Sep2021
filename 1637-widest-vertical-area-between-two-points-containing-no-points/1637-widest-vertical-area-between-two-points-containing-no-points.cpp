class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        int n=p.size();
        vector<int>x;
        for(int i=0;i<n;i++){
            x.push_back(p[i][0]);
        }
        sort(x.begin(),x.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        int res=0;
        for(int i=1;i<x.size();i++){
            res=max(res,x[i]-x[i-1]);
        }
        return res;
    }
};