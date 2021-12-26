class Solution {
    struct compare{
        bool operator()(vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        }
    };
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare());
        int count=0;
        int n=intervals.size();
        int end=INT_MIN;
        for(int i=0;i<n;i++){
           if(intervals[i][0]>=end) {
               count++;
               end=intervals[i][1];
           }
        }
        return n-count;
    }
};
//1,2 
//. 2,3
//1,  3 
//.   3,4
