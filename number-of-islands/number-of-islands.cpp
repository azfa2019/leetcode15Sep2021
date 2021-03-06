class Solution {
    int m,n;
    int dir[5]{1,0,-1,0,1};
public:
    int numIslands(vector<vector<char>>& grid) {
        this->m=grid.size();
        this->n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1') {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0'||grid[i][j]=='#') return;
        grid[i][j]='#';
        for(int d=0;d<4;d++){
            int r=i+dir[d];
            int c=j+dir[d+1];
            dfs(r,c,grid);
        }
    }
};