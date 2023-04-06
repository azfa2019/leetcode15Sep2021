class Solution {
public:
    int n,m;
    vector<vector<int>>g;
    int res;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    int closedIsland(vector<vector<int>>& _g) {
        g=_g;
        n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!g[i][j]) res+=dfs(i,j);
        return res;
    }
    int dfs(int x,int y){
        g[x][y]=1;
        int ans=1;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a<0||a>=n||b<0||b>=m) {
                ans=0;
                continue;
            }
            if(!g[a][b]&&!dfs(a,b)) ans=0;
        }
        return ans;
    }
};