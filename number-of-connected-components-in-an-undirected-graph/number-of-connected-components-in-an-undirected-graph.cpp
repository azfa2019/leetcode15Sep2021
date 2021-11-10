class Solution {
  public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>>g(n);
    for(auto e:edges){
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    vector<bool>visited(n,false);
    int count=0;
    for(int i=0;i<n;i++){
      if(visited[i]!=true){
        count++;
        dfs(i,visited,g);
      }
    }
    return count;
  }
  void dfs(int i, vector<bool>&visited, vector<vector<int>>&g){
    visited[i]=true;
    for(int next:g[i]){
      if(visited[next]) continue;
      dfs(next,visited,g);
    }
  }
};