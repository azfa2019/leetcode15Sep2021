class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
      vector<vector<int>>g(n);
      for(auto e:edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
      }
      int count=0;
      vector<int>visited(n,0);
      for(int i=0;i<n;i++){
        if(visited[i]==0) count++;
        dfs(i,visited,n,g);
      }
      return count;
    }
  void dfs(int i,vector<int>&visited,int n,vector<vector<int>>&g){
    if(i==n) return;
    if(visited[i]==1) return;
    visited[i]=1;
    for(int next:g[i]) {
      dfs(next,visited,n,g);
    }
  }
};