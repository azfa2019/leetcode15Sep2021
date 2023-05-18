class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<bool>in(n);
        for(auto& e:edges) in[e[1]]=1;
        for(int i=0;i<n;i++) if(!in[i]) ans.push_back(i);
        return ans;
    }
};