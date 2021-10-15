class Solution {
  vector<vector<int>> ans;
  vector<int>cur;
  public:
  vector<vector<int>> combinationSum3(int k, int n) {
    dfs(n,1,k,n);
    return ans;
  }
  void dfs(int remain,int curNum,int k,int n){
    if(cur.size()==k){
      if(remain==0) ans.push_back(cur);
      return;
    }
    for(int i=curNum;i<=9;i++){
      cur.push_back(i);
      dfs(remain-i,i+1,k,n);
      cur.pop_back();
    }
  }
};