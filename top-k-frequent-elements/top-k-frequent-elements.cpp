struct compare{
  bool operator()(pair<int,int>&a,pair<int,int>&b){
    return a.second>b.second;
  }
};
class Solution {
  public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare>pq;
    unordered_map<int,int>map0;
    for(int num:nums)
      map0[num]++;
    for(auto e:map0){
      pq.push({e.first,e.second});
      if(pq.size()>k) pq.pop();
    }

    vector<int>ans;
    while(!pq.empty()){
      ans.push_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};