class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(!board.size() || !board[0].size()) return;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int live=0;
                for(int r=max(0,i-1);r<=min(m-1,i+1);r++)
                    for(int c=max(0,j-1);c<=min(n-1,j+1);c++){
                        if(r==i && c==j) continue;
                        if(board[r][c]&1) live++;
                    }
                int cur=board[i][j]&1,next;
                if(cur){
                    if(live<2||live>3) next=0;
                    else next=1;
                }else{
                    if(live==3) next=1;
                    else next=0;
                }
                board[i][j]|=next<<1;
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j]>>=1;
    }
};
