
class Solution {
  struct compare{
    bool operator()(vector<int>&a,vector<int>&b){
      return a[1]>b[1];
    }
  };
  public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    priority_queue<vector<int>,vector<vector<int>>,compare> pq;
    sort(intervals.begin(),intervals.end());
    int ans=0;
    for(auto e:intervals){
      if(pq.empty()) pq.push(e);
      else{
        if(e[0]>=pq.top()[1]) pq.pop();
        pq.push(e);
      }
    }
    return pq.size();
  }
};