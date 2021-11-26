
class Solution {
  public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    int n=intervals.size();
    vector<pair<int,int>>all;
    for(auto e:intervals){
      all.push_back({e[0],1});
      all.push_back({e[1],-1});
    }
    sort(all.begin(),all.end());
    int count=0;
    int ans=0;
    for(auto e:all){
      count+=e.second;
      ans=max(ans,count);
    }
    return ans;
  }
};
