class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end());
      vector<int> e0{-1,-1};
      for(auto e:intervals){
        if(e0[1]>e[0]) return false;
        e0=e;
      }
      return true;
    }
};