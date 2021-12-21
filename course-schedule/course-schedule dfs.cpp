class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>g;
        for(auto p:prerequisites) g[p[1]].push_back(p[0]);
        vector<int>flag(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,g,flag)) return false;
        }
        return true;
    }
    bool dfs(int cur,unordered_map<int,vector<int>>&g,vector<int>&flag){
        if(flag[cur]==1) return false;
        if(flag[cur]==-1) return true;
        flag[cur]=1;
        for(int next:g[cur]){
            if(!dfs(next,g,flag)) return false;
        }
        flag[cur]=-1;
        return true;
    }
};
