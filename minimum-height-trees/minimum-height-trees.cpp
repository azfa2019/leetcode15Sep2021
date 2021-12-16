class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int,vector<int>>g;
        unordered_map<int,int>inDegree;
        for(int i=0;i<n;i++) inDegree[i]=0;
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }
        queue<int>qleaf;
        for(auto e:inDegree){
            if(e.second==1) qleaf.push(e.first);
        }
        int numNodes=n;
        while(numNodes>2){
            int leafSize=qleaf.size();
            numNodes-=leafSize;
            while(leafSize--){
                int cur=qleaf.front();qleaf.pop();
                for(int next:g[cur]){
                    inDegree[next]--;
                    if(inDegree[next]==1) qleaf.push(next);
                }
            }
        }
        vector<int>ans;
        while(!qleaf.empty()){
            ans.push_back(qleaf.front());
            qleaf.pop();
        }
        return ans;
    }
};