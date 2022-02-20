class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res=1;
        int n=intervals.size();
        int idx=0;
        int curEnd=intervals[0][1];
        for(int i=0;i<n;i++){
            if(intervals[i][1]>intervals[idx][1]) {
                if(intervals[idx][0]!=intervals[i][0]) res++;
                idx=i;
            }
        }
        return res;
    }
};
