class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hash;
        for(auto& s:strs) {
            auto s1=s;
            sort(s.begin(),s.end());
            hash[s].push_back(s1);
        }
        vector<vector<string>>ans;
        for(auto& [k,v]:hash) ans.push_back(v);
        return ans;
    }
};