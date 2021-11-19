class Solution {
  public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n=strs.size();
    unordered_map<string,vector<string>>map0;
    for(string s:strs){
      string cur=s;
      sort(cur.begin(),cur.end());
      map0[cur].push_back(s);
    }
    vector<vector<string>>ans;
    for(auto e:map0) ans.push_back(e.second);
    return ans;
  }
};