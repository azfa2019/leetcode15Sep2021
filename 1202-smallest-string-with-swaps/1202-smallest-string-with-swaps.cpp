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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        UnionFind uf=UnionFind(n);
        for(auto e:pairs) uf.unionnodes(e[0],e[1]);
        unordered_map<int,vector<int>>hash;
        for(int i=0;i<n;i++) hash[uf.findroot(i)].push_back(i);
        vector<char>res(n);
        for(auto [e,v]:hash){
            vector<int>c=v;
            sort(v.begin(),v.end(),[&](auto a,auto b){
                return s[a]<s[b];
            });
            for(int i=0;i<c.size();i++) res[c[i]]=s[v[i]];
        }
        s="";
        for(auto c:res) s+=c;
        return s;
    }
};