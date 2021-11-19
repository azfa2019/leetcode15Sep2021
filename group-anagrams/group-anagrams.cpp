class Solution {
  public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>map0;
    for(string s:strs){
      string key(26,0);
      for(char c:s) key[c-'a']++;
      map0[key].push_back(s);
    }
    vector<vector<string>>ans;
    for(auto e:map0) ans.push_back(e.second);
    return ans;
  }
};