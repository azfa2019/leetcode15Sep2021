class Solution {
    int m,n;
    int dir[5]{1,0,-1,0,1};
    public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]) 
                    if (dfs(board,i,j,0,word)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,int i,int j, int idx, string& word){
        if(idx==word.size()) return true;
        if(i<0||j<0||i>m-1||j>n-1||board[i][j]=='#') return false;
        if(word[idx]!=board[i][j]) return false;
        char c=board[i][j];
        board[i][j]='#';
        for(int d=0;d<4;d++){
            int r=i+dir[d];
            int c=j+dir[d+1];
            if(dfs(board,r,c,idx+1,word)) return true;
        }
        board[i][j]=c;
        return false;
    }
};