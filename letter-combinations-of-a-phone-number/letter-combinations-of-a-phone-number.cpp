class Solution {
  vector<string>ans;
  string cur;
  public:
  vector<string> letterCombinations(string digits) {
    if(digits.size()==0) return {};
    unordered_map<char,vector<string>>map{{'2',{"a","b","c"}},{'3',{"d","e","f"}},{'4',{"g","h","i"}},{'5',{"j","k","l"}},{'6',{"m","n","o"}},{'7',{"p","q","r","s"}},{'8',{"t","u","v"}},{'9',{"w","x","y","z"}}};
    dfs(0,digits,map);
    return ans;
  }
  void dfs(int curPos,string& digits,unordered_map<char,vector<string>>&map){
    if(curPos==digits.size()) {
      ans.push_back(cur);
      return;
    }
    for(string c:map[digits[curPos]]){
      cur+=c;
      dfs(curPos+1,digits,map);
      cur.pop_back();
    }
  }
};