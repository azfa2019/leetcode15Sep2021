struct Node{
    int x,y,z;
};
class Solution {
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        queue<Node>q;
        int n=g.size(),m=g[0].size(),INF=1e9;
        vector<vector<vector<int>>>dist(n,vector<vector<int>>(m,vector<int>(k+1,INF)));
        dist[0][0][0]=0;
        q.push({0,0,0});
        int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
        while(q.size()){
            auto t=q.front();q.pop();
            int d=dist[t.x][t.y][t.z];
            if(t.x==n-1 && t.y==m-1) return d;
            for(int i=0;i<4;i++){
                int x=t.x+dx[i],y=t.y+dy[i];
                if(x>=0 && x<n && y>=0 && y<m){
                    int z=t.z+g[x][y];
                    if(z<=k && dist[x][y][z]>d+1){
                        dist[x][y][z]=d+1;
                        q.push({x,y,z});
                    }
                }
            }
        }
        return -1;
    }
};