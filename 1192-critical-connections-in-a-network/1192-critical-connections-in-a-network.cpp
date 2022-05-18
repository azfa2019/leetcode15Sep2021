class Solution {
    int num=0;
    vector<int>dfn,low;
    vector<vector<int>>res;
    vector<vector<int>>adj;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn.resize(n); // 初始化一下工具人数组们
        low.resize(n);
        adj.resize(n);
        for (auto edge : connections) { // 邻接表存图
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int u = 0; u < n; u++) {
            if (!dfn[u]) tarjan(u, -1); // Tarjan 更新以 u 为根的搜索树。-1 表示根节点无父节点
        }
        return res;

    }
    void tarjan(int u,int fa){
        dfn[u] = low[u] = ++num;
        for (int v : adj[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (dfn[u] < low[v]) res.push_back({u, v});
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }


    }
};