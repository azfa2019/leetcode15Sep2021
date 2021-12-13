class Solution {
  public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n=intervals.size();
      if(n==0) return {newInterval};
      int i=0;
      vector<vector<int>>ans;
      while(i<n && intervals[i][1]<newInterval[0]) ans.push_back(intervals[i++]);
      while(i<n&& intervals[i][1]>=newInterval[0] && intervals[i][0]<=newInterval[1] ) {
          newInterval[0]=min(newInterval[0],intervals[i][0]);
          newInterval[1]=max(newInterval[1],intervals[i][1]);
          i++;
      }
      ans.push_back(newInterval);
      while(i<n) ans.push_back(intervals[i++]);
      return ans;
  }
};
// 1,3       6,9
// 1,3  4, 5  6,9
// 1,  3, 4,5   6,9 10,15
//    3          7

// 1,13  6,9
//  2   5
// 1,2  3, 5  6, 7  8,  10
//        4         8