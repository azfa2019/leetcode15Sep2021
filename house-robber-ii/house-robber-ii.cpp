class Solution {
  public:
  int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    vector<int>dp(n+1,0);
    /// 0 1 2 3 4
    return max(helper(0,n-2,nums),helper(1,n-1,nums));
  }
  int helper(int start,int end,vector<int>&nums){
    //cout<<start+2<<","<<end<<endl;
    vector<int>dp(end+1,0);
    dp[start]=nums[start];
    for(int i=start+1;i<=end;i++){
      dp[i]=max(i-2<0?0:dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[end];
  }
};