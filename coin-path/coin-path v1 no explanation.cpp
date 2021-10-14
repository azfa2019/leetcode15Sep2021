class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
      //dp[i]: min cost when reaching index i
      //dp[i]=min(dp[i],dp[i-x]+coins[i]) for all x: 1:maxJump
      int n=coins.size();
      vector<int>dp(n,INT_MAX/2);
      vector<int>path(n,-1);
      dp[n-1]=coins[n-1];
      for(int i=n-1;i>=0;i--){
        for(int k=1;k<=maxJump;k++){
          if(i+k>=coins.size()) continue;
          if(coins[i+k]==-1) continue;
          if(dp[i+k]+coins[i]<dp[i]){
            dp[i]=dp[i+k]+coins[i];
            path[i]=i+k;
          }
        }
      }
      //for(int i:path)
      //  cout<<i<<endl;
      vector<int>ans;
      int i=0;
      while(i<coins.size()){
        ans.push_back(i+1);
        if(i==coins.size()-1) break;
        if(path[i]==-1) return {};
        else i=path[i];
      }
      return ans;
    }
};
