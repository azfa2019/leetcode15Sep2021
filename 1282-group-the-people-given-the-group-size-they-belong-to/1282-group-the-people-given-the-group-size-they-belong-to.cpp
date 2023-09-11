class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,int>freq;
        unordered_map<int,vector<int>>pos;
        for(int i=0;i<g.size();i++) pos[g[i]].push_back(i);
        vector<vector<int>> res;
        for(auto& e:pos) {
            int cnt=e.second.size(),gsz=e.first;
            auto group=e.second;
            for(int i=0;i<cnt/gsz;i++){
                vector<int>cur;
                for(int j=0;j<gsz;j++) cur.push_back(group[i*gsz+j]);
                res.push_back(cur);
            }
        }
        return res;
    }
};