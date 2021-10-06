class Solution {
  public:
  int n;
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    n=nums.size();
    vector<int>tmp;
    vector<vector<int>>ans;
    dfs(0,tmp,ans,nums);
    return ans;
  }
  void dfs(int idx,vector<int>&tmp,vector<vector<int>>&ans,vector<int>&nums){
    if(tmp.size()>1) ans.push_back(tmp);
    if(idx==n)  return;
    unordered_set<int>set;
    for(int i=idx;i<n;i++){
      if(!tmp.empty() && nums[i]<tmp.back()) continue;
      if(set.find(nums[i])!=set.end()) continue;
      set.insert(nums[i]);
      tmp.push_back(nums[i]);
      dfs(i+1,tmp,ans,nums);
      tmp.pop_back();
    }
  }
};