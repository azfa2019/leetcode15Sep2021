class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) return {0};
        if(edges.size()==1) return {edges[0]};
        unordered_map<int,vector<int>>graph;
        unordered_map<int,int>inDegree;
        vector<int>res;
        queue<int>leaf;
        for(int i=0;i<n;i++) inDegree[i]=0;
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }
        for(auto e:inDegree) if(e.second==1) leaf.push(e.first);
        int numNodes=n;
        while(numNodes>2){
            int leafSize=leaf.size();
            numNodes-=leafSize;
            for(int i=0;i<leafSize;i++){
                int cur=leaf.front();
                leaf.pop();
                for(int child:graph[cur]){
                    inDegree[child]--;
                    if(inDegree[child]==1) leaf.push(child);
                }
            }
        }
        while(!leaf.empty()) {
            res.push_back(leaf.front());
            leaf.pop();
        }
        return res;
    }
};