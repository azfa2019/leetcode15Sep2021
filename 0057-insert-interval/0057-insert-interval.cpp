class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(intervals.empty()) return {newInterval};
        vector<vector<int>>res;
        int i=0;while(i<n&&intervals[i][1]<newInterval[0]) res.push_back(intervals[i]),i++;
        int st=newInterval[0],ed=newInterval[1];
        while(i<n&& intervals[i][0]<=newInterval[1]) st=min(intervals[i][0],st),ed=max(intervals[i][1],ed),i++;
        res.push_back({st,ed});
        for(;i<n;i++) res.push_back(intervals[i]);
        return res;
    }
};