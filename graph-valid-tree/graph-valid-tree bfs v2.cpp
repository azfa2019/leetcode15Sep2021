class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        queue<int>q{{0}};
        unordered_set<int>st{0};
        unordered_map<int,vector<int>>g;
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int next:g[cur]){
                if(st.find(next)!=st.end()) return false;
                st.insert(next);
                g[next].erase(remove(g[next].begin(),g[next].end(),cur),g[next].end());
                q.push(next);
            }
        }
        return st.size()==n;
    }
};
