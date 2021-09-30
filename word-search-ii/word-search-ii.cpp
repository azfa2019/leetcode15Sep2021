struct Trie{
  public:
  Trie* children[26]={};
  string word="";
  Trie(){
  }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      Trie* root=new Trie();
      for(string s:words){
        Trie* node=root;
        for(char c:s){
          if(node->children[c-'a']==nullptr) node->children[c-'a']=new Trie();
          node=node->children[c-'a'];
        }
        node->word=s;
      }
      vector<string>ans;
      for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
          dfs(i,j,root,board,ans);
        }
      }
      return ans;
    }
  void dfs(int i,int j,Trie* t, vector<vector<char>>&board,vector<string>&ans){
  if(i<0||i>board.size()-1||j<0||j>board[0].size()-1||board[i][j]=='#') return;
    char c=board[i][j];
    if(t->children[c-'a']==nullptr) return;
    t=t->children[c-'a'];
    if(t->word!="") {
      ans.push_back(t->word);
      t->word="";
    }
    board[i][j]='#';
    dfs(i+1,j,t,board,ans);
    dfs(i-1,j,t,board,ans);
    dfs(i,j+1,t,board,ans);
    dfs(i,j-1,t,board,ans);
    board[i][j]=c;
    return;
  }
};