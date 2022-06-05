class Solution {
public:
    int n;
    vector<bool>col,dg,udg;
    int dfs(int u){
        if(u==n) return 1;
        int res=0;
        for(int i=0;i<n;i++){
            if(!col[i]&&!dg[u+i]&&!udg[u-i+n]){
                col[i]=dg[u+i]=udg[u-i+n]=true;
                res+=dfs(u+1);
                col[i]=dg[u+i]=udg[u-i+n]=false;
            }
        }
        return res;
    }
    int totalNQueens(int _n) {
        n=_n;
        col=vector<bool>(n);
        dg=udg=vector<bool>(2*n);
        return dfs(0);
    }
};