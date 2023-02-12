class Solution {
public:
    int seats;
    vector<vector<int>>g;
    long long res;
    long long minimumFuelCost(vector<vector<int>>& roads, int _seats) {
        int n=roads.size()+1;
        seats=_seats;
        g.resize(n);
        for(auto& r:roads)
            g[r[0]].push_back(r[1]),g[r[1]].push_back(r[0]);
        dfs(0,-1);
        return res;
    }
    int dfs(int u,int fa){
        int nodes=1;
        for(int ne:g[u]){
            if(ne!=fa){
                int t=dfs(ne,u);
                res+=(t+seats-1)/seats;
                nodes+=t;
            }
        }
        return nodes;
    }
};