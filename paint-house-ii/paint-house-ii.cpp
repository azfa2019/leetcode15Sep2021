class Solution {
  public:
  int minCostII(vector<vector<int>>& costs) {
    int n=costs.size(),k=costs[0].size();
    vector<vector<int>>dp(n,vector<int>(k,0));
    //dp[i][j]: min cost, house 0:i, when the last house is painted with color j
    for(int j=0;j<k;j++)
      dp[0][j]=costs[0][j];
    for(int i=1;i<n;i++){
      vector<pair<int,int>>tmp;
      for(int j=0;j<k;j++) tmp.push_back({dp[i-1][j],j});
      sort(tmp.begin(),tmp.end()); //sort to get the minimum and second minimum dp[i-1][j]
      for(int j=0;j<k;j++){
        if(j==tmp[0].second) 
          dp[i][j]=tmp[1].first+costs[i][j];
        else 
          dp[i][j]=tmp[0].first+costs[i][j];
      }
    }
    int ans=INT_MAX;
    for(int j=0;j<k;j++) ans=min(ans,dp[n-1][j]);
    return ans;
  }
};
