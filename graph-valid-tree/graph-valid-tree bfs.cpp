class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      vector<unordered_set<int>>g(n);
      for(auto e:edges) g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);
      queue<int>q{{0}};
      unordered_set<int>set{{0}};
      while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto next:g[cur]){
          if(set.find(next)!=set.end()) return false;
          set.insert(next);
          q.push(next);
          g[next].erase(cur);
        }
      }
      return set.size()==n;
    }
};
