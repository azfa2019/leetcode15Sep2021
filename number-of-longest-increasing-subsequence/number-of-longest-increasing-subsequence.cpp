class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp(n,1);
      //dp[i]: the longest length, ending with nums[i]
      vector<int>count(n,1);
      for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
          if(nums[j]>=nums[i]) continue;
          if(dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
            count[i]=count[j];
          }else if(dp[i]==dp[j]+1){
            count[i]+=count[j];
          }
        }
      }
      int maxLen=0,ans=0;
      for(int i=0;i<n;i++){
        if(maxLen<dp[i]){
          maxLen=dp[i];
          ans=count[i];
        }else if(maxLen==dp[i]) ans+=count[i];
      }
      return ans;
        
    }
};