class UnionFind{
  public:
  vector<int>parent;
  vector<int>rank;
  UnionFind(int n){
    parent=vector<int>(n,0);
    rank=vector<int>(n,0);
    for(int i=0;i<parent.size();i++) parent[i]=i;
  }
  bool unionnodes(int n1,int n2){
    int p1=findroot(n1);
    int p2=findroot(n2);
    if(p1==p2) return false;
    if(rank[p1]<rank[p2]) parent[p1]=p2;
    else if(rank[p1]>rank[p2]) parent[p2]=p1;
    else parent[p2]=p1,rank[p1]++;
    return true;
  }
  int findroot(int n){
    if(n!=parent[n]) parent[n]=findroot(parent[n]);
    return parent[n];
  }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      if(edges.size()!=n-1) return false;
      UnionFind uf=UnionFind(n);
      for(auto e:edges){
        if(!uf.unionnodes(e[0],e[1])) return false;
      }
      return true;
      //unordered_set<int>set;
      //for(int i=0;i<n;i++) set.insert(uf.findroot(i));
      //return set.size()==1;
    }
};