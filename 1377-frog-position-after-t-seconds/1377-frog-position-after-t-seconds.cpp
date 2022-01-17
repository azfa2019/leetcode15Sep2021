class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>>g(n+1);
        for(auto e:edges)
            g[e[0]].push_back(e[1]),g[e[1]].push_back(e[0]);
        vector<int>seen(n+1);
        seen[1]=1;
        vector<double>p(n+1);
        p[1]=1.0;
        queue<int>q{{1}};
        while(t--){
            int size=q.size();
            while(size--){
                int cur=q.front();q.pop();
                int count=0;
                for(int next:g[cur]) 
                    if(!seen[next]) count++;
                for(int next:g[cur]){
                    if(!seen[next]){                                         
                        q.push(next);
                        p[next]=p[cur]/count;
                        seen[next]=1;
                    }
                }
                if(count>0) p[cur]=0;
            }
        }
        return p[target];
    }
};