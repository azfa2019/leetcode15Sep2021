class Solution {
  int n,total;
  public:
  bool splitArraySameAverage(vector<int>& nums) {
    total=accumulate(nums.begin(),nums.end(),0);
    n=nums.size();
    if(n==1) return false;
    vector<int>dp(total+1,0);
    dp[0]=1;//when selecting 0 numbers(the 0th bit=1), the  sum is 0

    int curSum=0;
    for(int i:nums){
      curSum+=i;
      for(int sum=curSum;sum>=i;sum--){
        dp[sum]|=(dp[sum-i]<<1);
        int k=dp[sum];
        if(sum*n%total==0){
          int num=sum*n/total;
          if(num!=0 && num!=n && (k>>num)&1) return true;
        }
      }
    }
    return false;
  }
};
//total/n=sum/num
//total*num/n=sum
//num=sum*n/total
//use dfs to find sum