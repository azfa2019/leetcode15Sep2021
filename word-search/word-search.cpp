class Solution {
    int m,n;
    string word;
    int dir[5]{1,0,-1,0,1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->m=board.size();
        this->n=board[0].size();
        this->word=word;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && dfs(0,i,j,board)) return true;
            }
        }
        return false;
    }
    bool dfs(int idx,int i,int j,vector<vector<char>>& board){
        if(idx==word.size()) return true;
        if(i<0 || i>m-1 || j<0 || j>n-1 || board[i][j]=='#') return false;
        if(board[i][j]!=word[idx]) return false;
        char c=board[i][j];
        board[i][j]='#';
        for( int d=0;d<4;d++){
            int r=i+dir[d];
            int c=j+dir[d+1];
            if(dfs(idx+1,r,c,board)) return true;
        }
        board[i][j]=c;
        return false;
    }
};