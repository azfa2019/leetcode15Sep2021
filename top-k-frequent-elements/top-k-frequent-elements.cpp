class Solution {
  struct compare{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
      return a.second<b.second;
    }
  };
  public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>map0;
    for(int num:nums) map0[num]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
    for(auto e:map0) pq.push(e);
    vector<int>ans;
    for(int i=0;i<k;i++) {
      ans.push_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};