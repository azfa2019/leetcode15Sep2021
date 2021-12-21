class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>g;
        unordered_map<int,int>indegree;
        for(int i=0;i<numCourses;i++) {
            indegree[i]=0;
        }
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>source;
        for(auto e:indegree){
            if(e.second==0) source.push(e.first);
        }
        vector<int>order;
        while(!source.empty()){
            int cur=source.front();source.pop();
            order.push_back(cur);
            for(int next:g[cur]){
                indegree[next]--;
                if(indegree[next]==0) source.push(next);
            }
        }
        return order.size()==numCourses;
    }
};