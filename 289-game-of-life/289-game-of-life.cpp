class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0 || board[0].size()==0) return;
        //if (board.empty() || board[0].empty()) return;
        
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int live=0;
                for(int x=max(0,i-1);x<=min(i+1,n-1);x++)
                    for(int y=max(0,j-1);y<=min(j+1,m-1);y++){
                        if(x==i && y==j) continue;
                        if(board[x][y]&1) live++;
                    }
                int cur=board[i][j]&1,next;
                if(cur){
                    if(live<2 || live>3) next=0;
                    else next=1;
                }else{
                    if(live==3) next=1;
                    else next=0;
                }
                board[i][j]|=next<<1;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                board[i][j]>>=1;
    }
};