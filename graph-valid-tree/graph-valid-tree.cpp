class UF{
  public:
  vector<int>parent;
  vector<int>rank;
  UF(int n){
    parent=vector<int>(n,0);
    rank=vector<int>(n,0);
    for(int i=0;i<n;i++) parent[i]=i;
  }
  bool unionNodes(int x,int y){
    x=findParent(x);
    y=findParent(y);
    if(x==y) return false;
    if(rank[x]>rank[y]) parent[y]=x;
    else if(rank[x]<rank[y]) parent[x]=y;
    else parent[y]=x,rank[x]++;
    return true;
  }
  int findParent(int x){
    if(x!=parent[x]) parent[x]=findParent(parent[x]);
    return parent[x];
  }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      UF uf=UF(n);
      for(auto e:edges){
        if(uf.unionNodes(e[0],e[1])==false) return false;
      }

      unordered_set<int>set;
      for(int i=0;i<n;i++) set.insert(uf.findParent(i));
      return set.size()==1;
    }
};