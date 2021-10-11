class Solution {
  unordered_map<string, vector<pair<string,double>>>map;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      //build the graph
      for(int i=0;i<equations.size();i++){
        map[equations[i][0]].push_back({equations[i][1],values[i]});
        map[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
      }
      vector<double>ans;
      unordered_set<string>visited;
      for(int i=0;i<queries.size();i++){
        if(map.find(queries[i][0])==map.end() || map.find(queries[i][1])==map.end()) {
          ans.push_back(-1.0);
          continue;
        }
        //visited.insert(queries[i][0]);
        ans.push_back(dfs(queries[i][0],queries[i][1],visited));
      }
      return ans;
    }
  double dfs(string& a, string& b,unordered_set<string>& visited){
    if(a==b) return 1.0;
    for(auto next:map[a]){
      string c=next.first;
      double ac=next.second;
      if(visited.find(c)!=visited.end()) continue;
      
      visited.insert(c);
      double cb=dfs(c,b,visited);
      visited.erase(c);
      if(cb!=-1.0) return (ac*cb);
    }
    return -1.0;
  }
};