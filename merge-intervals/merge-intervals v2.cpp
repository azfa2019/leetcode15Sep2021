class Solution {
  public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    for(auto e:intervals){
      if(ans.empty() || ans.back()[1]<e[0]) ans.push_back(e);
      else ans.back()[1]=max(ans.back()[1],e[1]);
    }
    return ans;
  }
};
