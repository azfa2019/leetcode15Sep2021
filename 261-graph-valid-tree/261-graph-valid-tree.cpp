class Solution {
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
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UF uf=UF(n);
        for(auto item:edges){
            if(uf.unionNodes(item[0],item[1])==false) return false;
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++) st.insert(uf.findParent(i));
        return st.size()==1;
        
    }
};