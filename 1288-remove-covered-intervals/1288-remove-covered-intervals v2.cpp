class Solution {
    struct compare{
        bool operator()(vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        }
    };
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),compare());
        int curEnd=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=curEnd) cnt++;
            else curEnd=intervals[i][1];
        }
        return n-cnt;
    }
};
