class Solution {
  int n;
  vector<vector<int>>ans;
  public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    this->n=graph.size();
    vector<int>path{0};
    dfs(0,path,graph);
    return ans;
  }
  void dfs(int cur,vector<int>&path,vector<vector<int>>& graph){
    if(cur==n-1) {
      ans.push_back(path);
      return;
    }
    for(int next:graph[cur]){
      path.push_back(next);
      dfs(next,path,graph);
      path.pop_back();
    }
  }
};