class Solution {
    static constexpr int DIRS[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        deque<pair<int,int>>q;
        q.emplace_front(0,0);
        while(q.size()){
            auto [i,j]=q.front();q.pop_front();
            for(auto&[dx,dy]:DIRS){
                int x=i+dx,y=j+dy;
                if(x>=0&&x<m&&y>=0&&y<n){
                    int g=grid[x][y];
                    if(dis[i][j]+g<dis[x][y]){
                        dis[x][y]=dis[i][j]+g;
                        g==0?q.emplace_front(x,y):q.emplace_back(x,y);
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};