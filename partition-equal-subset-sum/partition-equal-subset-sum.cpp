class Solution {
  public:
  bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int n:nums) sum+=n;
    if(sum%2!=0) return false;
    sum/=2;
    int n=nums.size();
    nums.insert(nums.begin(),0);
    vector<vector<int>>dp(n+1,vector<int>(sum+1,false));
    //dp[i][j]: true or false, when selecting i numbers to get a sum of j
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
      for(int s=1;s<=sum;s++){
        dp[i][s]=dp[i-1][s]||(s-nums[i]>=0?dp[i-1][s-nums[i]]:false);
      }
    }
    return dp[n][sum];
  }
};

//top down
//class Solution {
//  public:
//  bool canPartition(vector<int>& nums) {
//    //top down
//    //dp: n x (sum/2+1)
//    // in helper check select and no select
//    int sum=0;
//    for(int num:nums) sum+=num;
//    if(sum%2!=0) return false;
//    vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
//    return helper(dp,nums,sum/2,0);
//  }
//  bool helper(vector<vector<int>>&dp,const vector<int>& nums,int sum,int idx){
//    if(sum==0) return true;
//    if(nums.empty()|| idx>=nums.size()) return false;
//    if(dp[idx][sum]!=-1) return dp[idx][sum]==1?true:false;
//    if(nums[idx]<=sum){
//      if(helper(dp,nums,sum-nums[idx],idx+1))  return dp[idx][sum]=1;
//    }
//    dp[idx][sum]=helper(dp,nums,sum,idx+1)?1:0;
//    return dp[idx][sum];
//  }
//};
//bottom up:
//class Solution {
//  public:
//  bool canPartition(vector<int>& nums) {
//    //bottom up
//    //dp: n x (sum/2+1)
//    // in helper check select and no select
//    int sum=0;
//    for(int n:nums) sum+=n;
//    if(sum%2!=0) return false;
//    sum/=2;
//    int n=nums.size();
//    vector<vector<bool>>dp(n,vector<bool>(sum+1));
//    //boundary condition
//    for(int i=0;i<n;i++) dp[i][0]=true;
//    for(int s=1;s<=sum;s++) dp[0][s]=nums[0]==s?true:false;
//    for(int i=1;i<n;i++){
//      for(int s=1;s<=sum;s++){
//        //if(dp[i-1][s]) dp[i][s]=dp[i-1][s];
//        //else if(s>=nums[i]) dp[i][s]=dp[i-1][s-nums[i]];
//        dp[i][s]=dp[i-1][s]||(s>=nums[i]?dp[i-1][s-nums[i]]:false);
//      }
//    }
//    return dp[n-1][sum];
//  }
//};