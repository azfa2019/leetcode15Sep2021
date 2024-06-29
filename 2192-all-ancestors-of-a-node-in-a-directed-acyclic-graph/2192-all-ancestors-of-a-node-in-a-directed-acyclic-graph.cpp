class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(auto&e:edges) g[e[0]].push_back(e[1]);
        vector<vector<int>>ans(n);
        vector<int>vis(n,-1);
        int start;
        function<void(int)>dfs=[&](int x){
            vis[x]=start;
            for(int y:g[x]){
                if(vis[y]!=start){
                    ans[y].push_back(start);
                    dfs(y);
                }
            }
        };
        for(start=0;start<n;start++)
            dfs(start);
        return ans;
    }
};