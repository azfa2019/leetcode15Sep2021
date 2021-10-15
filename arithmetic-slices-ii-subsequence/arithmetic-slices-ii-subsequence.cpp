class Solution {
  public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    unordered_map<int,vector<int>>map;
    int n=nums.size();
    for(int i=0;i<n;i++) map[nums[i]].push_back(i);
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
      for(int j=0;j<i;j++){
        long m=nums[j]*2L-nums[i];
        if(m>INT_MAX || m<INT_MIN) continue;
        for(int k:map[m]) 
          if(k<j) dp[j][i]+=dp[k][j]+1;
      }
    }
    int ans=0;
    for(int j=0;j<n;j++)
      for(int i=j+1;i<n;i++)
        ans+=dp[j][i];
    return ans;
  }
};