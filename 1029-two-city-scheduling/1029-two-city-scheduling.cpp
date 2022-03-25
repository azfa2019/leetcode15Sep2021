class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res=0;
        sort(costs.begin(),costs.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]-a[1]<b[0]-b[1];
            });
        int n=costs.size()/2;
        for(int i=0;i<n;i++) res+=costs[i][0];
        for(int i=n;i<n*2;i++) res+=costs[i][1];
        return res;
    }
};