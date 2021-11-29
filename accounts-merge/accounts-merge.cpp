class UF{
  public:
  vector<int> parent;
  vector<int> rank;
  UF(int n){
    parent=vector<int>(n,0);
    rank=vector<int>(n,0);
    for(int i=0;i<n;i++) parent[i]=i;
  }
  int findParent(int x){
    if(x!=parent[x]) parent[x]=findParent(parent[x]);
    return parent[x];
  }
  bool unionNodes(int x,int y){
    int px=findParent(x);
    int py=findParent(y);
    if(px==py) return false;
    if(rank[px]>rank[py]) parent[py]=px;
    else if(rank[px]<rank[py]) parent[px]=py;
    else parent[px]=py, rank[py]++;
    return true;
  }
};
class Solution {
  public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string,int>mail2id;
    int n=accounts.size();
    UF uf=UF(n);
    for(int i=0;i<n;i++){
      int m=accounts[i].size();
      for(int j=1;j<m;j++){
        if(mail2id.find(accounts[i][j])==mail2id.end()) mail2id[accounts[i][j]]=i;
        else uf.unionNodes(i,mail2id[accounts[i][j]]);
      }
    }
    unordered_map<int,vector<string>>id2mail;
    for(auto e:mail2id){
      id2mail[uf.findParent(e.second)].push_back(e.first);
    }
    vector<vector<string>>ans;
    for(auto& e:id2mail){
      vector<string>tmp{accounts[e.first][0]};
      sort(e.second.begin(),e.second.end());
      tmp.insert(tmp.end(),e.second.begin(),e.second.end());
      ans.push_back(tmp);
    }
    return ans;
  }
};