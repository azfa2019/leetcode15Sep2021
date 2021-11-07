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
    if(rank[p1]>rank[p2]) parent[p2]=p1;
    else if(rank[p1]<rank[p2]) parent[p1]=p2;
    else parent[p1]=p2,rank[p2]++;
    return true;
  }
  int findParent(int i){
    if(i!=parent[i]) parent[i]=findParent(parent[i]);
    return parent[i];
  }
};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
      unordered_map<string,int>map0;
      int m=sentence1.size();
      if(m!=sentence2.size()) return false;
      int n=similarPairs.size();
      if(n==0) return false;
      int count=0;
      for(int i=0;i<m;i++) {
        if(map0.find(sentence1[i])==map0.end()) map0[sentence1[i]]=count++;
        if(map0.find(sentence2[i])==map0.end()) map0[sentence2[i]]=count++;
      }
      UF uf0=UF(map0.size());
      for(int i=0;i<n;i++){
        uf0.unionNodes(map0[similarPairs[i][0]], map0[similarPairs[i][1]]);
      }
      for(int i=0;i<m;i++)
        if(uf0.findParent(map0[sentence1[i]])!=uf0.findParent(map0[sentence2[i]])) return false;
      return true;
    }
};