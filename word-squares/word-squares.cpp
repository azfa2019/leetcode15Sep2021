class Solution {
  vector<vector<string>>ans;
  unordered_map<string,vector<string>>map0;
  int n;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
      this->n=words[0].size();
      for(string w:words){
        for(int i=0;i<n;i++)
          map0[w.substr(0,i)].push_back(w);
      }
      vector<string>cur;
      dfs(0,cur,words);
      return ans;
    }
  void dfs(int row,vector<string>&cur,vector<string>&words){
    if(row==n) {
      ans.push_back(cur);
      return;
    }
    string prefix;
    for(int i=0;i<row;i++){
      prefix.push_back(cur[i][row]);
    }
    for(auto word:map0[prefix]){
      cur.push_back(word);
      dfs(row+1,cur,words);
      cur.pop_back();
    }
  }
};