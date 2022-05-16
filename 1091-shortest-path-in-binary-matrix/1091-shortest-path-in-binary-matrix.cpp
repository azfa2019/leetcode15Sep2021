typedef pair<int,int> PII;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        if(g[0][0]) return -1;
        int n=g.size();
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<PII>q;
        dist[0][0]=1;
        q.push({0,0});
        int dx[]={-1,-1,-1,0,1,1,1,0};
        int dy[]={-1,0,1,1,1,0,-1,-1};
        while(q.size()){
            auto t=q.front();q.pop();
            for(int i=0;i<8;i++){
                int x=t.first+dx[i];
                int y=t.second+dy[i];
                if(x>=0 && x<n && y>=0 && y<n && dist[x][y]==-1 && g[x][y]==0) dist[x][y]=dist[t.first][t.second]+1,q.push({x,y});
            }
        }
        return dist[n-1][n-1];
    }
};