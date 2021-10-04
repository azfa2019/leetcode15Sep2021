class Solution {
  int n,total;
  public:
  bool splitArraySameAverage(vector<int>& nums) {
    total=accumulate(nums.begin(),nums.end(),0);
    n=nums.size();
    vector<vector<bool>>dp(total+1,vector<bool>(n,0));
    dp[0][0]=1;
    
    int curSum=0;
    for(int i:nums){
      curSum+=i;
      for(int sum=curSum;sum>=i;sum--){
        for(int num=n-1;num>=1;num--){
          if(dp[sum-i][num-1]){
            dp[sum][num]=1;
            if(total*num==n*sum) return true;
          }
        }
      }
    }
    return false;
  }
};
//total/n=sum/num
//total*num/n=sum
//use dfs to find sum
