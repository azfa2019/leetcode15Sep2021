class Solution {
  int n;
  vector<int> candidates;
  vector<vector<int>>ans;
  public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    this->n=candidates.size();
    this->candidates=candidates;
    vector<int>cur;
    helper(0,cur,target);
    return ans;
  }
  void helper(int idx,vector<int>&cur,int remain){
    if(idx==n || remain<0) return;
    if(remain==0) {
      ans.push_back(cur);
      return;
    }
    for(int i=idx;i<n;i++){
      cur.push_back(candidates[i]);
      helper(i,cur,remain-candidates[i]);
      cur.pop_back();
    }
  }
};