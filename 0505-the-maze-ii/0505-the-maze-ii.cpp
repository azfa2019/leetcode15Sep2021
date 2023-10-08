class Solution {
public:
    typedef pair<int,int>PII;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    int shortestDistance(vector<vector<int>>& g, vector<int>& s, vector<int>& e) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<PII>q;
        q.push({s[0],s[1]});
        dist[s[0]][s[1]]=0;
        while(q.size()){
            auto t=q.front();q.pop();
            for(int i=0;i<4;i++){
                int x=t.first,y=t.second,d=dist[x][y];
                while(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0) x+=dx[i],y+=dy[i],d++;
                x-=dx[i],y-=dy[i],d--;
                if(dist[x][y]>d){
                    dist[x][y]=d;
                    if(x!=e[0]||y!=e[1]) q.push({x,y});
                }
            }
        }
        if(dist[e[0]][e[1]]==INT_MAX) return -1;
        return dist[e[0]][e[1]];
    }
};