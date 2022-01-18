class Solution {
    vector<int>visited;
    vector<vector<int>>g;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited=vector<int>(numCourses,0);
        g=vector<vector<int>>(numCourses);
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0) 
                if(!dfs(i,visited)) return false;
        }
        return true;
    }
    bool dfs(int cur,vector<int>&visited){
        if(visited[cur]==1) return false;
        if(visited[cur]==2) return true;
        visited[cur]=1;
        for(int next:g[cur]){
            if(!dfs(next,visited)) return false;
        }
        visited[cur]=2;
        return true;
    }
};