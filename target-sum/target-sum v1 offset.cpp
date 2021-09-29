class Solution {
  public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int n=nums.size();
    nums.insert(nums.begin(),0);
    int offset=0;
    for(int n:nums) offset+=n;
    if(offset<S||-offset>S) return 0;
    vector<vector<int>>dp(n+1,vector<int>(2*offset+1,0));
    //dp[i][j]: # of ways to select first i elements to get a sum of j
    dp[0][offset]=1;
    for(int i=1;i<=n;i++){
      int num=nums[i];
      for(int s=-offset;s<=offset;s++){
        if(s+offset+num<=2*offset)
        dp[i][s+offset+num]+=dp[i-1][s+offset];
        if(s+offset-num>=0)
        dp[i][s+offset-num]+=dp[i-1][s+offset];
      }
    }
    return dp[n][S+offset];
  } 
};
//method 2
//class Solution {
//  public:
//  int findTargetSumWays(vector<int>& nums, int S) {
//    //method 2
//    //sum(s1)+sum(s2)=total sum
//    //sum(s1)-sum(s2)=S
//    //sum(s1)=(total sum+S)/2
//    //dp[i][j]: # of ways to get j with first i elements (from 1 to n elements, current is nums[i-1])
//    int n=nums.size();
//    int total=0;
//    for(int num:nums) total+=num;
//    if(total<S || (total+S)%2!=0) return 0;
//    int sum=(total+S)/2;
//    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
//    dp[0][0]=1;
//    for(int i=1;i<=n;i++){
//      for(int s=0;s<=sum;s++){
//        if(s-nums[i-1]>=0) dp[i][s]=dp[i-1][s]+dp[i-1][s-nums[i-1]];
//        else dp[i][s]=dp[i-1][s];
//      }
//    }
//    return dp[n][sum];
//  }
//};
////method 1
//class Solution {
//    public:
//    int findTargetSumWays(vector<int>& nums, int S) {//141
//        int n=nums.size();
//        nums.insert(nums.begin(),0);
//        //dp[i][j]: ways to assign symbols to make sum of integers equal to target j out of nums[i] 
//        int offset=0;
//        for(int n:nums) offset+=n;
//        if(offset<S || -offset>S) return 0;
//        vector<vector<int>>dp(n+1,vector<int>(2*offset+1,0));
//        dp[0][offset]=1;
//        for(int i=1;i<=n;i++){
//            int num=nums[i];
//            for(int s=-offset;s<=offset;s++){
//                if(s+offset+num<=2*offset)
//                    dp[i][s+offset+num]+=dp[i-1][s+offset];
//                if(s+offset-num>=0)
//                    dp[i][s+offset-num]+=dp[i-1][s+offset];
//            }
//        }
//        return dp[n][S+offset];
//    }
//};
