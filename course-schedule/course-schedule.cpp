class Solution {
  public:
  bool canFinish(int numCourses, vector<vector<int>>& pre) {
    vector<vector<int>>g(numCourses);
    for(auto p:pre) g[p[1]].push_back(p[0]);
    vector<int>flags(numCourses,0);
    for(int i=0;i<numCourses;i++){
      if(dfs(i,g,flags)==false) return false;
    }
    return true;
  }
  bool dfs(int i,vector<vector<int>>&g,vector<int>&flags){
    if(flags[i]==1) return false;
    if(flags[i]==-1) return true;
    flags[i]=1;
    for(int next:g[i]){
      if(dfs(next,g,flags)==false) return false;
    }
    flags[i]=-1;
    return true;
  }
};
//class Solution {
//  public:
//  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//    //topological sort
//    //inDegree: map
//    //source: vector
//    //res: vector
//    //graph: map
//    //initialize the graph and inDegree
//    unordered_map<int,int>inDegree;
//    unordered_map<int,vector<int>>graph;
//    vector<int>res;
//    queue<int>source;
//    
//    for(int i=0;i<numCourses;i++) inDegree[i]=0;
//    for(int i=0;i<prerequisites.size();i++) {
//      int k=prerequisites[i][0];
//      int v=prerequisites[i][1];
//      graph[k].push_back(v);
//      inDegree[v]++;
//    }
//    for(auto e:inDegree) if(e.second==0) source.push(e.first);
//    while(!source.empty()){
//      int cur=source.front();
//      source.pop();
//      res.push_back(cur);
//      for(int child:graph[cur]){
//        inDegree[child]--;
//        if(inDegree[child]==0) source.push(child);
//      }
//    }
//    return res.size()==numCourses;
//  }
//};