class UnionFind{
  public:
  unordered_map<string,string>parent;
  unordered_map<string,int>rank;
  UnionFind(vector<vector<string>>&similarPairs){
    for(auto p:similarPairs) rank[p[0]]=0,rank[p[1]]=0;
    for(auto p:rank) parent[p.first]=p.first;
  }
  string findroot(string& s){
    if(s!=parent[s]) parent[s]=findroot(parent[s]);
    return parent[s];
  }
  bool unionnodes(string& s1,string& s2){
    string p1=findroot(s1);
    string p2=findroot(s2);
    if(p1==p2) return false;
    if(rank[p1]>rank[p2]) parent[p2]=p1;
    else if(rank[p1]<rank[p2]) parent[p1]=p2;
    else parent[p1]=p2, rank[p2]++;
    return true;
  }
};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
      UnionFind uf=UnionFind(similarPairs);
      if(sentence1.size()!=sentence2.size()) return false;
      int m=similarPairs.size();
      if(m==0) return false;
      for(int i=0;i<m;i++) uf.unionnodes(similarPairs[i][0],similarPairs[i][1]);
      int n=sentence1.size();
      for(int i=0;i<n;i++){
        if(sentence1[i]==sentence2[i]) continue;
        string s1=uf.findroot(sentence1[i]);
        string s2=uf.findroot(sentence2[i]);
        //cout<<"s1="<<s1<<",s2="<<s2<<endl;
        if(s1!=s2) return false;
      }
      return true;
    }
};