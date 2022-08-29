typedef pair<int,int> PII;
class Solution {
public:
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int shortestDistance(vector<vector<int>>& g, vector<int>& s, vector<int>& e) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<PII>q;
        q.push({s[0],s[1]});
        dist[s[0]][s[1]]=0;
        while(q.size()){
            auto t=q.front();q.pop();
            for(int i=0;i<4;i++){
                int x=t.first,y=t.second,dcur=dist[t.first][t.second];
                while(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0) x+=dx[i],y+=dy[i],dcur++;
                x-=dx[i],y-=dy[i],dcur--;
                if(dist[x][y]>dcur){
                    dist[x][y]=dcur;
                    if(x!=e[0]||y!=e[1]) q.push({x,y});
                }
            }
        }
        if(dist[e[0]][e[1]]==INT_MAX) return -1;
        return dist[e[0]][e[1]];
    }
};