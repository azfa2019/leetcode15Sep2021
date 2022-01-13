class Solution {
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        if(n==0) return {newInterval};
        int i=0;
        while(i<n&& intervals[i][1]<newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        ans.push_back(newInterval);   
        while(i<n && intervals[i][0]<=ans.back()[1]) {
            ans.back()[0]=min(intervals[i][0],ans.back()[0]); 
            ans.back()[1]=max(intervals[i][1],ans.back()[1]); 
            i++;
        }
        while(i<n) ans.push_back(intervals[i]),i++;
        return ans;
    }
};