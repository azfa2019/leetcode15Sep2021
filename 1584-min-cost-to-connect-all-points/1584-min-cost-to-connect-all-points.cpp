class Solution {
public:
    int manDist(vector<vector<int>>& points,int i,int j){
        auto pi=points[i],pj=points[j];
        return abs(pi[0]-pj[0])+abs(pi[1]-pj[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        bool st[n+1];
        memset(st,0,sizeof st);
        int dist[n+1];
        memset(dist,0x3f,sizeof dist);
        int g[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                g[i][j]=g[j][i]=manDist(points,i,j);
        int res=0;
        for(int i=0;i<n;i++){
            int t=-1;
            for(int j=0;j<n;j++)
                if(!st[j] && (t==-1 || dist[t]>dist[j])) t=j;
            if(i) res+=dist[t];
            st[t]=true;
            for(int j=0;j<n;j++){
                dist[j]=min(dist[j],g[t][j]);
            }
        }
        return res;
    }
};