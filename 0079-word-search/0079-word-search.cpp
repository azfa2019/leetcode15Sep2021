class Solution {
public:
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    vector<vector<char>>board;
    string word;
    bool exist(vector<vector<char>>& _board, string _word) {
        board=_board,word=_word;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(dfs(0,i,j)) return true;
            }
        return false;
    }
    bool dfs(int u,int x,int y){
        if(board[x][y]!=word[u]) return false;
        if(u==word.size()-1) return true;
        char t=board[x][y];
        board[x][y]='.';
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0 && a<board.size() && b>=0 && b<board[0].size() && board[a][b]!='.') 
                if(dfs(u+1,a,b)) return true;
        }
        board[x][y]=t;
        return false;
    }
};