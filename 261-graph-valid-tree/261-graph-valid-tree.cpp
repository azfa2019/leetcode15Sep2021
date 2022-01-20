class Solution {
    public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        vector<bool>visited(n,false);
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        if(dfs(0,visited,-1,g)==false) return false;
        for(auto e:visited) 
            if(e==0) return false;
        return true;
    }
    bool dfs(int cur,vector<bool>&visited,int pre,vector<vector<int>>&g){
        if(visited[cur]) return false;
        visited[cur]=1;
        for(auto next:g[cur]){
            if(next!=pre){
                if(dfs(next,visited,cur,g)==false) return false;
            }
        }
        return true;
    }
};