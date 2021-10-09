struct Trie{
  public:
  Trie* children[26]={};
  string word="";
  Trie(){

  }
};
class Solution {
  public:
  int m,n;
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* root0=new Trie();
    for(string word:words){
      Trie* root=root0;
      for(char c:word){
        if(root->children[c-'a']==nullptr) root->children[c-'a']=new Trie();
        root=root->children[c-'a'];
      }
      root->word=word;
    }
    
    m=board.size(),n=board[0].size();
    vector<string>ans;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        dfs(i,j,root0,ans,board);
      }
    }
    return ans;
  }
  void dfs(int r,int c,Trie* root,vector<string>&ans,vector<vector<char>>&board){
    if(r<0||r>m-1||c<0||c>n-1||board[r][c]=='#') return;
    char ch=board[r][c];
    if(root->children[ch-'a']==nullptr) return;
    root=root->children[ch-'a'];
    if(root->word!="") {
      ans.push_back(root->word);
      root->word="";
    }
    board[r][c]='#';
    dfs(r+1,c,root,ans,board);
    dfs(r-1,c,root,ans,board);
    dfs(r,c+1,root,ans,board);
    dfs(r,c-1,root,ans,board);
    board[r][c]=ch;
  }
};