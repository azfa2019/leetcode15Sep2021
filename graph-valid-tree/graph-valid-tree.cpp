class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      vector<bool>visited(n,false);
      vector<vector<int>>g(n);
      for(auto e:edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
      }
      if(dfs(visited,g,0,-1)==false) return false;
      for(auto e:visited) if(e==false) return false;
      return true;
    }
  bool dfs(vector<bool>&visited,vector<vector<int>>&g,int cur,int pre){
    if(visited[cur]) return false;
    visited[cur]=true;
    for(auto next:g[cur]){
      if(next!=pre){
        if(dfs(visited,g,next,cur)==false) return false;
      }
    }
    return true;
  }
};