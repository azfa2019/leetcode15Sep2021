class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>g(n);
        for(auto item:edges){
            g[item[0]].push_back(item[1]);
            g[item[1]].push_back(item[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans++;
                dfs(i,visited,n,g);
            }
        }
        return ans;
    }
    void dfs(int cur,vector<int>&visited,int n,vector<vector<int>>&g){
        if(visited[cur]==1) return;
        visited[cur]=1;
        for(int next:g[cur]){
            dfs(next,visited,n,g);
        }
    }
};