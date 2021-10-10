class Solution {
  int dp[101][101][21];
  public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    //dp[i][j][k]: min cost of painting first houses 0:i, j neighborhoods last house color k 

    houses.insert(houses.begin(),0);
    cost.insert(cost.begin(),{0});

    for(int i=0;i<=m;i++)
      for(int j=0;j<=target;j++)
        for(int k=0;k<=n;k++)
          dp[i][j][k]=INT_MAX/2;
    
    for(int k=0;k<=n;k++)
      dp[0][0][k]=0; //BC: 0 house 0 neighborhoods, cost is 0

    for(int i=1;i<=m;i++){
      if(houses[i]!=0){
        for(int j=1;j<=target;j++){
          int k=houses[i];
          for(int kk=1;kk<=n;kk++){
            if(kk==k)//last house is same color as the house before, same # of neighborhoods
              dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
            else //last house is different from the house before, 
              dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][kk]);
          }
        }
      }else{
        for(int j=1;j<=target;j++){
          vector<pair<int,int>> tmp;// saves the min cost of dp[i-1][j-1][k]
          for(int k=1;k<=n;k++) tmp.push_back({dp[i-1][j-1][k],k});
          sort(tmp.begin(),tmp.end());//now tmp[0] saves the min cost, tmp[1] saves the 2nd min cost
          for(int k=1;k<=n;k++){
            dp[i][j][k]=dp[i-1][j][k]+cost[i][k-1]; //assume the last house has the same color as the house before
            //if the last house has a different color as the last house 
            if(k!=tmp[0].second) dp[i][j][k]=min(dp[i][j][k],tmp[0].first+cost[i][k-1]);
            else dp[i][j][k]=min(dp[i][j][k],tmp[1].first+cost[i][k-1]);
          }
        }
      }
    }
    int ans=INT_MAX/2;
    for(int k=1;k<=n;k++)
      ans=min(ans,dp[m][target][k]);
    return (ans==INT_MAX/2)?-1:ans;
  }
};