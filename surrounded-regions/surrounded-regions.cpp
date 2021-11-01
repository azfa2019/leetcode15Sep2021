class Solution {
  int dir[5]={1,0,-1,0,1};
  int m,n;
public:
    void solve(vector<vector<char>>& board) {
      m=board.size(),n=board[0].size();
      for(int i=0;i<m;i++){
        if(board[i][0]=='O') dfs(i,0,board);
        if(board[i][n-1]=='O') dfs(i,n-1,board);
      }
      for(int i=1;i<=n-2;i++){
        if(board[0][i]=='O') dfs(0,i,board);
        if(board[m-1][i]=='O') dfs(m-1,i,board);
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(board[i][j]=='#') board[i][j]='O';
          else if(board[i][j]=='O') board[i][j]='X';
        }
      }
    }
  void dfs(int i,int j,vector<vector<char>>& board){
    if(i<0||i>m-1||j<0||j>n-1||board[i][j]!='O') return;
    board[i][j]='#';
    for(int d=0;d<4;d++){
      int r=i+dir[d];
      int c=j+dir[d+1];
      dfs(r,c,board);
    }
  }
};