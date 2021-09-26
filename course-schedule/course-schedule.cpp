class Solution {
  public:
  bool canFinish(int numCourses, vector<vector<int>>& pre) {
    queue<int>source;
    unordered_map<int,int>inDegree;
    for(int i=0;i<numCourses;i++) inDegree[i]=0;
    unordered_map<int,vector<int>>graph;
    for(int i=0;i<pre.size();i++){
      graph[pre[i][1]].push_back(pre[i][0]);
      inDegree[pre[i][0]]++;
    }
    for(auto p:inDegree) if(p.second==0) source.push(p.first);
    vector<int>order;
    while(!source.empty()){
      int cur=source.front();
      source.pop();
      order.push_back(cur);
      for(int next:graph[cur]){
        inDegree[next]--;
        if(inDegree[next]==0) source.push(next);
      }
    }
    return order.size()==numCourses;
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