class Solution {
  public:
  string alienOrder(vector<string>& words) {
      int n=words.size();
      unordered_map<char,vector<char>>g;
      unordered_map<char,int>inDegree;
      for(string w:words)
          for(char c:w)
              inDegree[c]=0;
      for(int i=0;i<n-1;i++){
          if(words[i].find(words[i+1])==0 && words[i].size()>words[i+1].size()) return "";
          for(int j=0;j<min(words[i].size(),words[i+1].size());j++){
              if(words[i][j]==words[i+1][j]) continue;
              else{
                  g[words[i][j]].push_back(words[i+1][j]);
                  inDegree[words[i+1][j]]++;
                  break;
              }
          }
      }
      queue<char>source;
      string ans="";
      for(auto e:inDegree) if(e.second==0) source.push(e.first);
      while(!source.empty()){
          char cur=source.front();source.pop();
          ans.push_back(cur);
          for(char next:g[cur]){
              inDegree[next]--;
              if(inDegree[next]==0) source.push(next);
          }
      }
      return ans.size()==inDegree.size()?ans:"";
  }
};