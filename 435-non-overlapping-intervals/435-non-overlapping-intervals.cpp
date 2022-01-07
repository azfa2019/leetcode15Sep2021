class Solution {
    struct compare{
        bool operator()(vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        }
    };
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),compare());
        int count=0;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]<end) continue;
            count++;
            end=intervals[i][1];
        }
        return n-count;
    }
};