class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      int n=nums.size();
      int m=multipliers.size();
      nums.insert(nums.begin(),0);
      vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
      dp[0][0]=0;
      int ans=INT_MIN;
      
      for(int len=1;len<=m;len++){
        for(int i=0;i<=len;i++){
          int j=len-i;
          if(i>=1) dp[i][j]=max(dp[i][j],dp[i-1][j]+nums[i]*multipliers[i+j-1]);
          if(j>=1) dp[i][j]=max(dp[i][j],dp[i][j-1]+nums[n-j+1]*multipliers[i+j-1]);
          if(i+j==m) ans=max(ans,dp[i][j]);
        }
      }
      return ans;
    }
};
//dp[i][j]=max score of nums[i:j]
//j-i+1 elements, total n elements,
//1st in multiplier: m elements, mth in multiplier: 1 element
//j-i+1 elements: n+1-(j-i+1) th element, n-j+i th element
//element index: n-j+i-1 
//dp[i][j]=max(dp[i+1][j]+multipliers[n-j+i-1]*nums[i], dp[i][j-1]+multipliers[n-j+i-1]*nums[j])