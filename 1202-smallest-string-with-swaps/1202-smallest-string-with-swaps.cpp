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
        vector<char>rs(n);
        UnionFind ds(n);
        for(auto e:pairs) ds.unionnodes(e[0],e[1]);
        
        unordered_map<int,vector<int>>hash;
        for(int i=0;i<n;i++) hash[ds.findroot(i)].push_back(i);
        for(auto [k,v]:hash){
            vector<int>c=v;
            sort(v.begin(),v.end(),[&](auto a,auto b){
                return s[a]<s[b];
            });
            for(int i=0;i<c.size();i++) rs[c[i]]=s[v[i]];
        }
        s="";
        for(auto c:rs) s+=c;
        return s;
    }
};