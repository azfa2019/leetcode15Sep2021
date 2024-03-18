class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int res=1,ed=points[0][1];
        for(int i=1;i<points.size();i++){
            auto e=points[i];
            if(ed<e[0]){
                res++;
                ed=e[1];
            }
        }
        return res;
    }
};