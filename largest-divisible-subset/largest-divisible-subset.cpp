class Solution {
  public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int>dp(n,1);
    vector<int>prev(n,-1);
    dp[0]=1;
    for(int i=1;i<n;i++){
      for(int j=0;j<=i-1;j++){
        if(nums[i]%nums[j]==0){
          if(dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
            prev[i]=j;
          }
        }
      }
    }
    int len=-1,idx=-1;
    for(int i=0;i<n;i++){
      if(len<dp[i]){
        len=dp[i];
        idx=i;
      }
    }
    vector<int>ans;
    while(ans.size()!=len){
      ans.push_back(nums[idx]);
      idx=prev[idx];
    }
    return ans;
  }
};