class Solution {
  public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int>dp(n,1);
    vector<int>prev(n,-1);
    dp[0]=1;
    
    vector<int>ret;
    for(int i=1;i<n;i++){
      for(int j=0;j<=i-1;j++){
        if(nums[i]%nums[j]==0) {
          if(dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
            prev[i]=j;
          }
        }
      }
    }
    int maxIdx=-1,maxLen=-1;
    for(int i=0;i<n;i++){
      if(dp[i]>maxLen){
        maxLen=dp[i];
        maxIdx=i;
      }
    }
    vector<int>ans;
    int pos=maxIdx;
    while(pos!=-1){
      ans.push_back(nums[pos]);
      pos=prev[pos];
    }
    return ans;
  }
};
//dp[i]
//dp[i-1]
//dp[i]=dp[j] +1 for j=0, 1 ..i-1