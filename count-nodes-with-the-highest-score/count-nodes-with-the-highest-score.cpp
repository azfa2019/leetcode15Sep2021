typedef long long ll;
class Solution {
  unordered_map<int,vector<int>>map;
  int n;
  ll maxproduct;
  int maxcount;
  public:
  int countHighestScoreNodes(vector<int>& parents) {
    n=parents.size();
    maxproduct=1;
    maxcount=0;
    for(int i=0;i<n;i++) map[parents[i]].push_back(i);
    dfs(0);
    return maxcount;
  }
  int dfs(int node){
    ll product=1;
    int count=0;
    for(int child:map[node]){
      int childsize=dfs(child);
      count+=childsize;
      if(childsize>0) product*=childsize;
    }
    if(n-1-count>0) product*=n-1-count;
    if(product>maxproduct) {
      maxproduct=product;
      maxcount=1;
    }else if(product==maxproduct) maxcount++;
    return count+1;
  }
};