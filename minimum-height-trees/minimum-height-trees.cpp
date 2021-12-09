class Solution {
    public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) return {0};
        if(edges.size()==1) return {edges[0]};
        unordered_map<int,vector<int>>graph;
        unordered_map<int,int>inDegree;
        for(int i=0;i<n;i++) inDegree[i]=0;
        queue<int>q;
        for(auto e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }
        for(auto e:inDegree) 
            if(e.second==1) q.push(e.first);
        int numNodes=n;
        while(numNodes>2){
            int leafSize=q.size();
            numNodes-=leafSize;
            while(leafSize--){
                int cur=q.front();q.pop();
                for(int connect:graph[cur]){
                    inDegree[connect]--;
                    if(inDegree[connect]==1) q.push(connect);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};