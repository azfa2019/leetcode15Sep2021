class Solution {
public:
    vector<vector<int>>tree;
    vector<bool>vis;
    vector<int>ans;
    string labels;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string _labels) {
        tree.resize(n);
        vis.resize(n);
        ans.resize(n);
        labels=_labels;
        for(auto& e:edges) tree[e[0]].push_back(e[1]),tree[e[1]].push_back(e[0]);
        vector<int>tmp(26);
        dfs(0,tmp);
        return ans;
    }
    void dfs(int cur,vector<int>&a){
        if(vis[cur]) return;
        vis[cur]=true;
        vector<int>tmp(26);
        for(auto& ne:tree[cur]) dfs(ne,tmp);
        ans[cur]=++tmp[labels[cur]-'a'];
        for(int i=0;i<26;i++) a[i]+=tmp[i];
    }
};