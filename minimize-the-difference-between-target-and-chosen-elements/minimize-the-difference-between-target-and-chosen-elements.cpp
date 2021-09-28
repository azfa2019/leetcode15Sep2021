class Solution {
  public:
  int dp[70][5000];
  int n,m;
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    n=mat.size(),m=mat[0].size();
    memset(dp,-1,sizeof(dp));
    int ans=INT_MAX;
    dfs(0,0,mat,ans,target);
    return ans;

  }
  int dfs(int idx,int sum,vector<vector<int>>&mat,int&ans,int target){
    if(idx==n)  {
      return abs(sum-target);
    }
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    for(int i:mat[idx]) {
      ans=min(ans,dfs(idx+1,sum+i,mat,ans,target));
    }
    return dp[idx][sum]=ans;
  }
};