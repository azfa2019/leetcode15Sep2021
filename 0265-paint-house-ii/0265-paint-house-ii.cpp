class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()||costs[0].empty()) return 0;
        vector<vector<int>>dp=costs;
        int min1=-1,min2=-1;
        for(int i=0;i<dp.size();i++){
            int last1=min1,last2=min2;
            min1=-1,min2=-1;
            for(int j=0;j<dp[0].size();j++){
                if(j!=last1) dp[i][j]+=last1<0?0:dp[i-1][last1];
                else dp[i][j]+=last2<0?0:dp[i-1][last2];
                if(min1<0||dp[i][j]<dp[i][min1]) min2=min1,min1=j;
                else if(min2<0||dp[i][j]<dp[i][min2]) min2=j;
            }
        }
        return dp.back()[min1];
    }
};