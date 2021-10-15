class Solution {
  public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>cur{};
    dfs(0,n,k,cur,ans);
    return ans;
  }
  void dfs(int curPos,int n,int k,vector<int>&cur,vector<vector<int>>&ans){
    if(cur.size()==k) {
      ans.push_back(cur);
      return;
    }
    if(curPos==n) return;
    for(int i=curPos+1;i<=n;i++){
      cur.push_back(i);
      dfs(i,n,k,cur,ans);
      cur.pop_back();
    }
  }
};