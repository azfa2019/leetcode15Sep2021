class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto s:strs){
            string cur(26,'a');
            for(char c:s) cur[c-'a']++;
            mp[cur].push_back(s);
        }
        for(auto e:mp) ans.push_back(e.second);
        return ans;
    }
};