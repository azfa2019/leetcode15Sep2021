class UF{
  public:
  vector<int>parent;
  vector<int>rank;
  UF(int n){
    parent=vector<int>(n+1,0);
    rank=vector<int>(n+1,0);
    for(int i=0;i<parent.size();i++) parent[i]=i;
  }
  bool unionNodes(int n1,int n2){
    int p1=findRoot(n1);
    int p2=findRoot(n2);
    if(p1==p2) return false;
    if(rank[p1]<rank[p2]) {
      parent[p1]=p2;
    }else if(rank[p1]>rank[p1]) parent[p2]=p1;
    else {
      parent[p2]=p1;
      rank[p1]++;
    }
    return true;
  }
  int findRoot(int n){
    if(parent[n]!=n) parent[n]=findRoot(parent[n]);
    return parent[n];
  }
};
class Solution {
  public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UF uf0=UF(edges.size());
    for(auto e:edges){
        if(!uf0.unionNodes(e[0],e[1])) return e;
    }
    return {};
  }
};