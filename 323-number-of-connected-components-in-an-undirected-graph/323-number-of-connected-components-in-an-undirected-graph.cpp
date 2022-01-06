class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>g(n);
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,g,visited);
            }
        }
        return count;
    }
    void dfs(int idx,vector<vector<int>>&g,vector<int>&visited){
        if(visited[idx]==1) return;
        visited[idx]=1;
        for(int next:g[idx]) dfs(next,g,visited);
    }
};