class UF{
  public:
  vector<int>parent;
  vector<int>rank;
  UF(int n){
    parent=vector<int>(n,0);
    rank=vector<int>(n,0);
    for(int i=0;i<n;i++)
      parent[i]=i;
  }
  int findParent(int i){
    if(parent[i]!=i) parent[i]=findParent(parent[i]);
    return parent[i];
  }
  bool unionNodes(int x,int y){
    x=findParent(x);
    y=findParent(y);
    if(x==y) return false;
    if(rank[x]<rank[y]) parent[x]=y;
    else if(rank[x]>rank[y]) parent[y]=x;
    else parent[y]=x,rank[x]++;
    return true;
  }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n=edges.size();
      UF uf=UF(n+1);
      for(auto e:edges){
        if(uf.unionNodes(e[0],e[1])==false) return e;
      }
      return {-1,-1};
    }
};
