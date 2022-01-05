class Solution {
    public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>g(n);
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        if(dfs(0,visited,g,-1)==false) return false;
        for(int i=0;i<n;i++) if(visited[i]==0) return false;
        return true;
    }
    bool dfs(int idx,vector<int>&visited, vector<vector<int>>&g,int pre){
        if(visited[idx]==1) return false;
        if(visited[idx]==-1) return true;
        visited[idx]=1;
        for(auto next:g[idx]){
            if(next!=pre)
                if(dfs(next,visited,g,idx)==false) return false;
        }
        visited[idx]=-1;
        return true;
    }
};