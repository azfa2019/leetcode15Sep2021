class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,vector<int>>pos;
        vector<vector<int>> res;
        for(int i=0;i<g.size();i++) {
            int x=g[i];
            pos[x].push_back(i);
            if(pos[x].size()==x) {
                res.push_back(pos[x]);
                pos[x].clear();
            }
        }
        return res;
    }
};