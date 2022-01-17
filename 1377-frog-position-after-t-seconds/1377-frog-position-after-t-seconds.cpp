class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1) return 1.0;
        vector<vector<int>>g(101);
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(1,0,t,target,g);
    }
    double dfs(int u,int fa,int t,int target,vector<vector<int>>&g){
        int sz=g[u].size();
        if(!t || (fa && sz==1)) {
              if(u==target) return 1;
              else return 0;
        }
        double p=1.0/(fa?sz-1:sz),maxx=0;
        for(int i=0;i<sz;i++){
            int v=g[u][i];
            if(v==fa) continue;
            double next=dfs(v,u,t-1,target,g);
            if(next>0) {
                maxx=next;
                break;
            }
        }
        return p*maxx;
    }
};