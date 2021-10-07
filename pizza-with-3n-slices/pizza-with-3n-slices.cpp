class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
      int n=slices.size();
      return max(helper(0,n-2,n/3,slices),helper(1,n-1,n/3,slices));
    }
  int helper(int start, int end,int m,vector<int>&nums){
    vector<vector<int>>dp(end+1,vector<int>(m+1,0));
    dp[start][1]=nums[start];
    for(int i=start+1;i<=end;i++){
      for(int j=1;j<=m;j++){
        dp[i][j]=max(((i-2<start)?0:dp[i-2][j-1])+nums[i],dp[i-1][j]);
      }
    }
    return dp[end][m];
  }
};