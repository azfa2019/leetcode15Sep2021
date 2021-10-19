class Solution {
  public:
  int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size();
unordered_map<int,int>mp;
vector<vector<int>>dp(n,vector<int>(n,2));
    int ans=0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        int first=2*nums[i]-nums[j];
        if(mp.find(first)!=mp.end()) dp[i][j]=dp[mp[first]][i]+1;
        ans=max(ans,dp[i][j]);
      }
      mp[nums[i]]=i;
    }
    return ans;
  }
};