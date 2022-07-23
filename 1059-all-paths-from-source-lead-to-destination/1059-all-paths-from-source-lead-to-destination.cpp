class Solution {
    enum State {nv,tr,fa};
public:
    bool dfs(vector<vector<int>>& mp,int source,int dest,vector<State>visited){
        if(mp[source].empty()) {
            if(source==dest) return true;
            return false;
        }
        if(visited[source]!=nv) return visited[source]==tr;
        visited[source]=fa;
        for(auto child:mp[source])
            if(!dfs(mp,child,dest,visited)) return false;
        visited[source]=tr;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>mp(n,vector<int>());
        for(auto& e:edges) mp[e[0]].push_back(e[1]);
        vector<State> visited(n,nv);
        return dfs(mp,source,destination,visited);
    }
};