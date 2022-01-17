class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>g(numCourses);
        for(auto p:pre) g[p[1]].push_back(p[0]);
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(!dfs(i,g,visited)) return false;
        return true;
    }
    bool dfs(int idx,vector<vector<int>>&g,vector<int>&visited){
        if(visited[idx]==1) return false;
        if(visited[idx]==-1) return true;
        visited[idx]=1;
        for(int next:g[idx])
            if(dfs(next,g,visited)==false) return false;
        visited[idx]=-1;
        return true;
    }
};