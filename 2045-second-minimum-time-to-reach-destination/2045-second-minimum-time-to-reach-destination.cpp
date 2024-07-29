typedef pair<int,int>PII;
const long long mod=1e9+7;
typedef long long LL;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        auto get=[&](int d)->int{
            int t=d/change;
            if(t%2) return (t+1)*change+time;
            return d+time;
        };
        vector<vector<int>>g(n);
        for(auto& e:edges){
            int u=e[0],v=e[1];
            u--,v--;
            g[u].push_back(v),g[v].push_back(u);
        }
        vector<PII>dis(n,PII(1e9,1e9));
        dis[0].first=0;
        queue<PII>q;
        q.push(PII(0,0));
        while(q.size()){
            auto[u,d]=q.front();q.pop();
            for(int v:g[u]){
                int ne=get(d);
                if(ne<dis[v].first){
                    dis[v].first=ne;
                    q.push(PII(v,ne));
                }else if(ne>dis[v].first && ne<dis[v].second){
                    dis[v].second=ne;
                    q.push(PII(v,ne));
                }
            }
            
        }
        return dis.back().second;
    }
};