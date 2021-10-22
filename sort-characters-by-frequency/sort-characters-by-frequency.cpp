class Solution {
  struct greater{
    bool operator()(const pair<int,char>&a,const pair<int,char>&b) {
      return a.first>b.first;
    }
  };
  public:
  string frequencySort(string s) {
    priority_queue<pair<int,char>>pq;
    unordered_map<char,int>mp;
    for(char c:s) mp[c]++;
    for(auto e:mp)
      pq.push({e.second,e.first});
    //cout<<pq.top().first<<endl;
    //cout<<pq.top().second<<endl;
    string ans;
    while(!pq.empty()){
      for(int i=0;i<pq.top().first;i++)
        ans.push_back(pq.top().second);
      //cout<<(pq.top().second)<<endl;
      pq.pop();
    }
    return ans;
  }
};