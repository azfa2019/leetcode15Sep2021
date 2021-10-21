class Solution {
  long M=1e9+7;
  long dp[201][101];
  public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    //dp[f][c]: # of routes when arriving at locations[c], with fuel f left

    int n=locations.size();
    dp[fuel][start]=1;

    for(int f=fuel;f>=0;f--){
      for(int c=0;c<n;c++){
        for(int d=0;d<n;d++){
          if(c==d) continue;
          int gas=abs(locations[c]-locations[d]);
          if(f+gas<=fuel)
            dp[f][c]=(dp[f][c]+dp[f+gas][d])%M;
        }
      }
    }
    int ans=0;
    for(int f=0;f<=fuel;f++)
      ans=(ans+dp[f][finish])%M;
    return ans;
  }
};