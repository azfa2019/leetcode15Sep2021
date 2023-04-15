class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
                int size = targetPath.size();
        
        // build graph
        vector<vector<int>> g(n);
        for (vector<int> &road: roads) {
            g[road[0]].push_back(road[1]);
            g[road[1]].push_back(road[0]);
        }
        
        vector<vector<int>> dp(n, vector<int>(size, INT_MAX));
        vector<vector<int>> parent(n, vector<int>(size, INT_MAX));
        
        // base case
        string start = targetPath[0];
        for (int i = 0; i < n; i++) {
            dp[i][0] = (names[i] == start) ? 0: 1;
        }
        for(int i=1;i<size;i++){
            for(int j=0;j<n;j++){
                string city=targetPath[i];
                int cost=(names[j]!=city);
                int minCost=INT_MAX;
                for(int& nei:g[j]){
                    if(dp[nei][i-1]+cost<minCost){
                        minCost=dp[nei][i-1]+cost;
                        parent[j][i]=nei;
                    }
                }
                dp[j][i]=minCost;
            }
        }
        vector<int>result(size);
        int finalMinCost=INT_MAX;
        int last=-1;
        for(int i=0;i<n;i++)
            if(dp[i][size-1]<finalMinCost){
                finalMinCost=dp[i][size-1];
                last=i;
            }
        for(int i=size-1;i>=0;i--){
            result[i]=last;
            last=parent[last][i];
        }
        return result;
    }
};