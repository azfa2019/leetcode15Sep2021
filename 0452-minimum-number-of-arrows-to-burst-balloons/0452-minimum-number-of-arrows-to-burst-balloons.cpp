class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        long long res=0,ed=LLONG_MIN;
        for(int i=0;i<points.size();i++){
            if(points[i][0]>ed){
                res++;
                ed=points[i][1];
            }
        }
        return res;
    }
};