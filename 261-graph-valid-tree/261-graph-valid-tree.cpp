class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>>g(n);
        for(auto e:edges){
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        queue<int>q{{0}};
        unordered_set<int>st{{0}};
        while(q.size()){
            int cur=q.front();q.pop();
            for(int next:g[cur]){
                if(st.find(next)!=st.end()) return false;
                st.insert(next);
                q.push(next);
                g[next].erase(cur);
            }
        }
        return st.size()==n;
    }
};