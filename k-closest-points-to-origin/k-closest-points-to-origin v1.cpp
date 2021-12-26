class Solution {
  struct compare{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
      return a.first*a.first+a.second*a.second<b.first*b.first+b.second*b.second;
    }
  };
  public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
    for(auto e:points){
      pq.push({e[0],e[1]});
      if(pq.size()>k) pq.pop();
    }
    vector<vector<int>>ans;
    while(!pq.empty()) {
      ans.push_back({pq.top().first,pq.top().second});
      pq.pop();
    }
    return ans;

  }
};
