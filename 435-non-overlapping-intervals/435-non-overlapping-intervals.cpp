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
        int i=0;
        while(i<n){
            count++;
            int j=i;
            while(j<n && intervals[j][0]<intervals[i][1]) j++;
            i=j;
        }
        return n-count;
    }
};