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
      int m=sentence1.size();
      int n=sentence2.size();
      if(m!=n) return false;
      unordered_set<string>set;
for(string s:sentence1) set.insert(s);
for(string s:sentence2) set.insert(s);
      for(auto e:similarPairs) {
        set.insert(e[0]);
        set.insert(e[1]);
      }
      vector<string>all(set.begin(),set.end());
      unordered_map<string,int>map;
      for(int i=0;i<all.size();i++) map[all[i]]=i;
      UF uf=UF(all.size());
      for(int i=0;i<similarPairs.size();i++){
        uf.unionNodes(map[similarPairs[i][0]],map[similarPairs[i][1]]);
      } 
      for(int i=0;i<n;i++) {
        if(uf.findParent(map[sentence1[i]])!=uf.findParent(map[sentence2[i]])) return false;
      }
      return true;
    }
};
