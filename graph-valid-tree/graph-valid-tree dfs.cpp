class Solution {
  public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>>g(n);
    vector<bool>visited(n,false);
    for(auto e:edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    if(dfs(g,visited,0,-1)==false) return false;
    for(auto e:visited) 
      if(e==false) return false;
    return true;
  }
  bool dfs(vector<vector<int>>&g,vector<bool>&visited,int cur,int pre){
    if(visited[cur]) return false;
    visited[cur]=true;
    for(auto next:g[cur]){
      if(next!=pre){
        if(dfs(g,visited,next,cur)==false) return false;
      }
    }
    return true;
  }
};
