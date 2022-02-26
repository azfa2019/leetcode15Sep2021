typedef pair<int,int> PII;
#define x first
#define y second
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<PII>q;
        vector<vector<int>>f(1<<n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            f[1<<i][i]=0;
            q.push({1<<i,i});
        }
        while(q.size()){
            auto t=q.front();q.pop();
            for(auto node: graph[t.y]){
                int s=t.x|1<<node;
                if(f[s][node]>f[t.x][t.y]+1){
                    f[s][node]=f[t.x][t.y]+1;
                    q.push({s,node});
                }
            }
        }
        int res=1e8;
        for(int i=0;i<n;i++) res=min(res,f[(1<<n)-1][i]);
        return res;
    }
};
