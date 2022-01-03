class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>sources;
        for(int i=0;i<numCourses;i++) 
            if(indegree[i]==0) sources.push(i);
        vector<int>ans;
        while(!sources.empty()){
            int cur=sources.front();sources.pop();
            ans.push_back(cur);
            for(auto next:g[cur]){
                indegree[next]--;
                if(indegree[next]==0) sources.push(next);
            }
        }
        return ans.size()==numCourses;
    }
};