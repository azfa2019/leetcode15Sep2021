class Solution {
    int num=0;
    vector<int>dfn,low;
    vector<vector<int>>res;
    vector<vector<int>>adj;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn.resize(n),low.resize(n),adj.resize(n);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
            for(int i=0;i<n;i++)
                if(!dfn[i]) tarjan(i,-1);
        return res;
    }
    void tarjan(int u,int fa){
        dfn[u]=low[u]=++num;
        for(int v:adj[u]){
            if(v==fa) continue;
            if(!dfn[v]){
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
                if(dfn[u]<low[v]) res.push_back({u,v});
            }else low[u]=min(low[u],dfn[v]);
        }
    }
};