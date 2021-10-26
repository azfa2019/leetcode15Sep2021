class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
      //dp[i][j]: waste ending with nums[i] with j resize operations
      // x x x x [x x x]
      //.         s   i
      //s is the last resize operation, it can happen anywhere before i
      int n=nums.size();
      
      vector<vector<int>>dp(n,vector<int>(k+1,INT_MAX/2));
      //set bc: dp[i][0], min waste when taking 0 resize ops
      int sum=0,mx=0;
      for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
        sum+=nums[i];
        dp[i][0]=mx*(i+1)-sum;
      }
      for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
          int mx=0,sum=0;
          for(int s=i;s>=1;s--){
            mx=max(mx,nums[s]);
            sum+=nums[s];
            dp[i][j]=min(dp[i][j],dp[s-1][j-1]+mx*(i-s+1)-sum);
          }
        }
      }
      int ans=INT_MAX/2;
      for(int i=0;i<=k;i++)
        ans=min(ans,dp[n-1][k]);
      return ans;
    }
};