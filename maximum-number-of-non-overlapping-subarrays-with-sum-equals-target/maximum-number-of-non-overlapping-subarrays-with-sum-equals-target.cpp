class Solution {
  public:
  int maxNonOverlapping(vector<int>& nums, int target) {
    //dp[i]: up to nums[i]
    //dp[i-1]:  k
    // x x x x  x
    //.    k    i
    //dp[i][j]: 
    int n=nums.size();
    nums.insert(nums.begin(),0);
    vector<int>dp(n+1,0);
    unordered_map<int,int>map0;
    vector<int>presum(n+1,0);
    for(int i=1;i<=n;i++) presum[i]=presum[i-1]+nums[i];
    map0[0]=0;
    for(int i=1;i<=n;i++){
      dp[i]=dp[i-1];
      if(map0.find(presum[i]-target)!=map0.end()){
        int j=map0[presum[i]-target];
        dp[i]=max(dp[i],dp[j]+1);
      } 
      map0[presum[i]]=i;
    }
    return dp[n];
  }
};