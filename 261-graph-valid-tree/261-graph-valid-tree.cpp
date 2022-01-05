class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        vector<vector<int>>g(n);
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        if(!dfs(0,visited,g,-1)) return false;
        for(auto e:visited) if(!e) return false;
        return true;
    }
    bool dfs(int idx,vector<bool>&visited, vector<vector<int>>&g,int pre){
        if(visited[idx]) return false;
        visited[idx]=true;
        for(int next:g[idx]){
            if(pre!=next){
                if(!dfs(next,visited,g,idx)) return false;
            }
        }
        return true;
    }
};