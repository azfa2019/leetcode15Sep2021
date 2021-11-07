class UF{
  public:
  vector<int>parent;
  vector<int>rank;
  UF(int n){
    parent=vector<int>(n,0);
    rank=vector<int>(n,0);
    for(int i=0;i<n;i++) parent[i]=i;
  }
  bool unionNodes(int n1,int n2){
    int p1=findParent(n1);
    int p2=findParent(n2);
    if(p1==p2) return false;
    if(rank[p1]<rank[p2]) parent[p1]=p2;
    else if(rank[p1]>rank[p2]) parent[p2]=p1;
    else parent[p1]=p2,rank[p2]++;
    return true;
  }
  int findParent(int n){
    if(n!=parent[n]) parent[n]=findParent(parent[n]);
    return parent[n];
  }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
      int n=edges.size();
      UF uf0=UF(n+1);
      for(auto e:edges)
        if(uf0.unionNodes(e[0],e[1])==false) return e;
      return {};
    }
};