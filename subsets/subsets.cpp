class Solution {
  public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>ans;
    for(int mask=0;mask<(1<<n);mask++){
    vector<int>cur;
      for(int i=0;i<n;i++){
        if((mask&(1<<i))!=0) cur.push_back(nums[i]);
      }
      ans.push_back(cur);
    }
    return ans;
  }
};