class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      unordered_map<int,int>map;
      for(int num:nums) map[num]++;
      int maxNum=*max_element(nums.begin(),nums.end());
      vector<int>dp(maxNum+1,0);//dp[i]: max points ending with i
      dp[1]=map[1];
      for(int i=2;i<=maxNum;i++)
        dp[i]=max(dp[i-2]+map[i]*i,dp[i-1]);
      return dp[maxNum];
    }
};