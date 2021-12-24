class Solution {
    public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        unordered_map<int,vector<int>>g;
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        if(dfs(0,visited,g,-1)==false) return false;
        for(int i=0;i<n;i++)
            if(visited[i]!=-1) return false;
        return true;
    }
    bool dfs(int i,vector<int>&visited, unordered_map<int,vector<int>>&g,int pre){
        if(visited[i]==1) return false;
        if(visited[i]==-1) return true;
        visited[i]=1;
        for(int next:g[i]){
            if(next!=pre)
                if(dfs(next,visited,g,i)==false) return false;
        }
        visited[i]=-1;
        return true;
    }
};