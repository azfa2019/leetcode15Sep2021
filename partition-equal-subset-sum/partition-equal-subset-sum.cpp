class Solution {
    public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sum/=2;
        unordered_set<int>st{0};
        for(int num:nums){
            auto st2=st;
            for(auto x:st2){
                if(x+num==sum) return true;
                else st.insert(x+num);
            }
        }
        return false;
    }
};
// 1 5 11 5
// 0 1  // 5 6 // 11 12 16 17
//

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