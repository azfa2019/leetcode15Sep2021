class Solution {
  public:
  bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int,vector<int>>g;
    for(auto e:edges){
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    stack<int>stack0;
    stack0.push(0);
    unordered_map<int,int>parent;
    parent[0]=-1;
    while(!stack0.empty()){
      int cur=stack0.top();
      stack0.pop();
      for(int nei:g[cur]){
        if(parent[cur]==nei) continue;
        if(parent.find(nei)!=parent.end()) return false;
        parent[nei]=cur;
        stack0.push(nei);
      }
    }
    return parent.size()==n;
  }
};