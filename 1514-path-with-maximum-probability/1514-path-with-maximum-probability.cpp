class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>g(n);
        priority_queue<pair<double,int>>heap;
        heap.emplace(1.0,start);
        vector<bool>seen(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double prob=succProb[i];
            g[u].emplace_back(v,prob);
            g[v].emplace_back(u,prob);
        }
        while(heap.size()){
            auto [prob,u]=heap.top();
            heap.pop();
            if(u==end) return prob;
            if(seen[u]) continue;
            seen[u]=true;
            for(auto& [ne,edgeprob]:g[u]){
                if(seen[ne]) continue;
                heap.emplace(prob*edgeprob,ne);
            }
        }
        return 0; 
    }
};