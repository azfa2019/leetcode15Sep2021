class TicTacToe {
public:
    vector<int>row,col;
    int dg=0,udg=0;
    int n;
    TicTacToe(int _n) {
        n=_n;
        row.resize(n),col.resize(n);
    }
    
    int move(int r, int c, int player) {
        int sign=player==1?1:-1;
        row[r]+=sign,col[c]+=sign;
        if(r==c) dg+=sign;
        if(r+c==n-1) udg+=sign;
        if(abs(row[r])==n ||
          abs(col[c])==n||
          abs(dg)==n||
          abs(udg)==n) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */