class Solution {
public:
    vector<vector<string>>ans;
    vector<string>path;
    vector<bool>col,dg,udg;
    int n;
    void dfs(int u){
        if(u==n) {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<n;i++){
            if(!col[i]&& !dg[u+i] && !udg[u-i+n]){
                path[u][i]='Q';
                col[i]=dg[u+i]=udg[u-i+n]=true;
                dfs(u+1);
                path[u][i]='.';
                col[i]=dg[u+i]=udg[u-i+n]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int _n) {
        n=_n;
        dg=vector<bool>(2*n+1,false);
        udg=vector<bool>(2*n+1,false);
        col=vector<bool>(n,false);
        path=vector<string>(n,string(n,'.'));
        dfs(0);
        return ans;
    }
};