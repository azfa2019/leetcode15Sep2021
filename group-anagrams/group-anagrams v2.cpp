class Solution {
  public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>>mp;
      int n=strs.size();
      for(int i=0;i<n;i++){
          string tmp(26,0);
          for(char c:strs[i]){
              tmp[c-'a']++;
          }
          mp[tmp].push_back(strs[i]);
      }
      vector<vector<string>>ans;
      for(auto e:mp){
          ans.push_back(e.second);
      }
      return ans;
  }
};
