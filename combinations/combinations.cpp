class Solution {
  vector<vector<int>>ans;
  vector<int>cur;
  public:
  vector<vector<int>> combine(int n, int k) {
    cur={};
    dfs(1,k,n);
    return ans;
  }
  void dfs(int idx,int k,int n){
    //if(idx==n+1) return;
    if(cur.size()==k) {
      ans.push_back(cur);
      return;
    }
    for(int i=idx;i<=n;i++){
      cur.push_back(i);
      dfs(i+1,k,n);
      cur.pop_back();
    }
  }
};