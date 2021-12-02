class Solution {
    int m,n;
    int dir[5]={1,0,-1,0,1};
    vector<vector<int>> heights;
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->m=heights.size();
        this->n=heights[0].size();
        this->heights=heights;
        auto pac=heights,atl=heights;
        for(int i=0;i<m;i++){
            dfs(i,0,pac);
            dfs(i,n-1,atl);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,pac);
            dfs(m-1,j,atl);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]==-1 && atl[i][j]==-1) ans.push_back({i,j});
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<vector<int>>& sea){
        if(i<0||j<0||i>m-1||j>n-1||sea[i][j]==-1) return;
        int h=sea[i][j];
        sea[i][j]=-1;
        for(int d=0;d<4;d++){
            int r=i+dir[d];
            int c=j+dir[d+1];
            if(r<0||c<0||r>m-1||c>n-1) continue;
            if(heights[r][c]>=h){
                dfs(r,c,sea);
            }
        }
    }
};