class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()<=1) return points.size();
        sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int res=0;
        long long ed=LLONG_MIN;
        for(auto e:points){
            if(ed<e[0]){
                res++;
                ed=e[1];
            }
        }
        return res;
    }
};