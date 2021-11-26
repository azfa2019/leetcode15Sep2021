typedef long long ll;
class Solution {
  unordered_map<int,vector<int>>map;
  unordered_map<ll,int>mapCount;
  int n;
  public:
  int countHighestScoreNodes(vector<int>& parents) {
    n=parents.size();
    for(int i=0;i<n;i++) map[parents[i]].push_back(i);
    countNode(0);
    ll maxProduct=0;
    int ans=0;
    for(auto e:mapCount){
      if(e.first>maxProduct) {
        maxProduct=e.first;
        ans=e.second;
      }
    }
    return ans;
  }
  int countNode(int node){
    int count=0;
    ll product=1;
    for(int child:map[node]){
      int tmpCount=countNode(child);
      count+=tmpCount;
      if(tmpCount>0) product*=tmpCount;
    }
    if(n-1-count>0) product*=n-1-count;
    mapCount[product]++;
    return count+1;
  }
};