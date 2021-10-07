class Solution {
  public:
  int m,n;
  vector<int>dir{1,0,-1,0,1};
  bool exist(vector<vector<char>>& board, string word) {
    m=board.size(),n=board[0].size();
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(board[i][j]==word[0]) 
          if (dfs(0,i,j,board,word)) return true;
    return false;
  }
  bool dfs(int idx,int r,int c,vector<vector<char>>& board, string& word){
    if(idx==word.size()) return true;
    if(r<0||r>m-1||c<0||c>n-1||board[r][c]=='#'||word[idx]!=board[r][c]) return false;
    char ch=board[r][c];
    board[r][c]='#';
    for(int i=0;i<4;i++){
      int rn=r+dir[i];
      int cn=c+dir[i+1];
      //if(rn<0||rn>m-1||cn<0||cn>n-1||board[rn][cn]=='#') continue;
      if (dfs(idx+1,rn,cn,board,word)) return true;
      }
    board[r][c]=ch;
    return false;
  }
};