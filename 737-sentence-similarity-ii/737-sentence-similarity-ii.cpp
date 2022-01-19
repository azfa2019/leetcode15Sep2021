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
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        unordered_set<string>st;
        if(sentence1.size()!=sentence2.size()) return false;
        int n=sentence1.size();
        for(auto s:sentence1) st.insert(s);
        for(auto s:sentence2) st.insert(s);
        for(auto item: similarPairs) st.insert(item[0]),st.insert(item[1]);
        vector<string>words(st.begin(),st.end());
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++) mp[words[i]]=i;
        UF uf=UF(words.size());
        for(auto item:similarPairs){
            uf.unionNodes(mp[item[0]],mp[item[1]]);
        }
        for(int i=0;i<n;i++){
            if(uf.findParent(mp[sentence1[i]])!=uf.findParent(mp[sentence2[i]])) return false;
        }
        return true;
    }
};