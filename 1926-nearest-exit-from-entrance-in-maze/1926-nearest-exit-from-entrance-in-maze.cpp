typedef pair<int,int> PII;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
class Solution {
public:
    
    int nearestExit(vector<vector<char>>& g, vector<int>& e) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<PII>q;
        q.push({e[0],e[1]});
        dist[e[0]][e[1]]=0;
        int res=0;
        while(q.size()){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto t=q.front();q.pop();
                if(g[t.first][t.second]=='.'&& (!(t.first==e[0]&&t.second==e[1])) && (t.first==0 || t.second==0||t.first==n-1||t.second==m-1)) return res;
                for(int j=0;j<4;j++){
                    int x=t.first+dx[j],y=t.second+dy[j];
                    if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]=='.'){
                        if(dist[x][y]>dist[t.first][t.second]+1){
                            dist[x][y]=dist[t.first][t.second]+1;
                            q.push({x,y});
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};