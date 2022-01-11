class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto s:strs){
            auto tmp=s;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(s);
        }
        for(auto e:mp) ans.push_back(e.second);
        return ans;
    }
};