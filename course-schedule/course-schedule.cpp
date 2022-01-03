class Solution {
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0) return true;
        vector<vector<int>>g(numCourses);
        for(auto p:prerequisites) g[p[1]].push_back(p[0]);
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if (dfs(i,visited,g)==false) return false;
        return true;
    }
    bool dfs(int idx,vector<int>& visited,vector<vector<int>>&g){
        if(visited[idx]==1) return false;
        if(visited[idx]==-1) return true;
        visited[idx]=1;
        for(auto next:g[idx]){
            if (dfs(next,visited,g)==false) return false;
        }
        visited[idx]=-1;
        return true;
    }
};