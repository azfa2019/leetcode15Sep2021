class Solution {
    int m,n;
    int dir[5]={1,0,-1,0,1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->m=heights.size();
        this->n=heights[0].size();
        vector<vector<int>>pac(m,vector<int>(n,0));
        vector<vector<int>>atl(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dfs(i,0,pac,heights);
            dfs(i,n-1,atl,heights);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,pac,heights);
            dfs(m-1,j,atl,heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atl[i][j]==1 && pac[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<vector<int>>&sea,vector<vector<int>>& heights){
        if(i<0||j<0||i>m-1||j>n-1||sea[i][j]==1) return;
        sea[i][j]=1;
        for(int d=0;d<4;d++){
            int r=i+dir[d];
            int c=j+dir[d+1];
            if(r<0||c<0||r>m-1||c>n-1) continue;
            if(heights[r][c]>=heights[i][j]) dfs(r,c,sea,heights);
        }
    }
};