class Solution {
    vector<vector<int>>g;
    unordered_set<string>land;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        g=grid;
        for(int i=0;i<g.size();i++)
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1) {
                    set<string>s;
                    dfs(i,j,i,j,s);
                    string t="";
                    for(auto str:s) t+=str+"_";
                    land.insert(t);
                }
            }
        return land.size();
    }
    void dfs(int x0,int y0,int x,int y,set<string>&s){
        g[x][y]=0;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<g.size() && ny>=0 && ny<g[0].size() && g[nx][ny]==1) {
                string tmp=to_string(nx-x0)+"_"+to_string(ny-y0);
                s.insert(tmp);
                dfs(x0,y0,nx,ny,s);
            }
        }
    }
};
