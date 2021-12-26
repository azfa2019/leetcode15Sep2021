class Solution {
    struct compare{
        bool operator()(vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        }
    };
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare());
        int n=intervals.size();
        int count=0;
        int i=0;
        while(i<n){
            count++;
            int j=i+1;
            while(j<n && intervals[j][0]<intervals[i][1]) j++;
            i=j;
        }
        return n-count;
    }
};
//1,2 
//. 2,3
//1,  3 
//.   3,4