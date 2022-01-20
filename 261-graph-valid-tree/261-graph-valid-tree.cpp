class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(auto item:edges){
            g[item[0]].push_back(item[1]);
            g[item[1]].push_back(item[0]);
        }
        unordered_set<int>st;
        queue<int>q;
        q.push(0),st.insert(0);
        while(q.size()){
            int cur=q.front();q.pop();
            for(int next:g[cur]){
                if(st.find(next)!=st.end()) return false;
                q.push(next);
                st.insert(next);
                g[next].erase(remove(g[next].begin(),g[next].end(),cur),g[next].end());
            }
        }
        return st.size()==n;
    }
};