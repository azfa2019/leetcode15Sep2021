class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        k=k%(m*n);
        vector<int>grid0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                grid0.push_back(grid[i][j]);
        int l=m*n-k;
        reverse(grid0.begin(),grid0.begin()+l);
        reverse(grid0.begin()+l,grid0.end());
        reverse(grid0.begin(),grid0.end());
        for(int i=0;i<n*m;i++)
        {
            int r=i/n,c=i%n;
            grid[r][c]=grid0[i];
        }
        return grid;
    }
};