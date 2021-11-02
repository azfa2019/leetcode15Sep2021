class Trie{
  public:
  Trie* children[26]={};
  string word="";
  Trie(){}
};
class Solution {
  int m,n;
  int dir[5]={1,0,-1,0,1};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      Trie* root=new Trie();
      for(string w:words){
        Trie* node=root;
        for(char c:w){
          if(node->children[c-'a']==nullptr) node->children[c-'a']=new Trie();
          node=node->children[c-'a'];
        }
        node->word=w;
      }
      m=board.size(),n=board[0].size();
      vector<string>ans;
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
          dfs(i,j,board,root,ans);
        }
      return ans;
    }
  void dfs(int i,int j, vector<vector<char>>& board,Trie* node,vector<string>&ans){
    if(i<0||i>m-1||j<0||j>n-1||board[i][j]=='#') return;
    char c=board[i][j];
    if(node->children[c-'a']==nullptr) return;
    node=node->children[c-'a'];
    if(node->word!="") ans.push_back(node->word),node->word="";
    board[i][j]='#';
    for(int k=0;k<4;k++){
      int r=i+dir[k];
      int c=j+dir[k+1];
      dfs(r,c,board,node,ans);
    }
    board[i][j]=c;
  }
};