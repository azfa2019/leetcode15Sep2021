class Solution {
public:
    vector<int>ans;
    int n,m;
    vector<vector<int>>g;
    vector<int> findBall(vector<vector<int>>& g_) {
        g=g_;
        n=g.size(),m=g[0].size(),ans.resize(m);
        for(int i=0;i<m;i++) ans[i]=dfs(0,i);
        return ans;
    }
    int dfs(int i,int j){
        if(i==n) return j;
        if(g[i][j]==1 && j+1<m && g[i][j+1]==1) return dfs(i+1,j+1);
        else if(g[i][j]==-1 && j>0 && g[i][j-1]==-1) return dfs(i+1,j-1);
        return -1;
    }
};