class Solution {
    static constexpr int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][1]>1&&grid[1][0]>1) return -1;
        int dis[m][n];
        memset(dis,0x3f,sizeof dis);
        dis[0][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        pq.emplace(0,0,0);
        for(;;){
            auto [d,i,j]=pq.top();
            pq.pop();
            if(d>dis[i][j]) continue;
            if(i==m-1&&j==n-1) return d;
            for(auto&q:dirs){
                int x=i+q[0],y=j+q[1];
                if(x>=0&&x<m&&y>=0&&y<n){
                    int nd=max(d+1,grid[x][y]);
                    nd+=(nd-x-y)%2;
                    if(nd<dis[x][y]){
                        dis[x][y]=nd;
                        pq.emplace(nd,x,y);
                    }
                }
            }
        }
    }
};