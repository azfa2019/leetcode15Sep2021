class Solution {
  struct compare{
    bool operator()(vector<int>&a,vector<int>&b){
      return a[1]<b[1];
    }
  };
  public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),compare());
    int i=0;
    int count=0;
    while(i<intervals.size()){
      int j=i+1;
      count++;
      while(j<intervals.size() && intervals[j][0]<intervals[i][1]) j++;
      i=j;
    }

    return intervals.size()-count; 
  }
};