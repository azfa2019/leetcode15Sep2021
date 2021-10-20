class Solution {
  public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
    int n=nums.size();
    vector<vector<long>>dp(n,vector<long>(n,0));
    //dp[i][j]: # of arithmetic subseq ending with nums[i] and nums[j]
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        long first=2*(long)nums[i]-(long)nums[j];
        if(first>INT_MAX||first<INT_MIN) continue;
        if(mp.find(first)!=mp.end()) {
          for(long k:mp[first])
            if(k<i) dp[i][j]+=dp[k][i]+1;
        }
      }
    }
    long ans=0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        ans+=dp[i][j];
      }
    }
    return ans;
  }
};