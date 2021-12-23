class Solution {
    vector<int>ans;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        //if(n==0) {
        //    vector<int>ans;
        //    for(int i=0;i<numCourses;i++) ans.push_back(i);
        //    return ans;
        //}
        unordered_map<int,vector<int>>g;
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
        vector<int>flag(numCourses);
        stack<int>stck;
        for(int i=0;i<numCourses;i++){
            if(dfs(i,g,flag)==false) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool dfs(int i,unordered_map<int,vector<int>>&g,vector<int>&flag){
        if(flag[i]==1) return false;
        if(flag[i]==-1) return true;
        flag[i]=1;
        for(int next:g[i]){
            if(dfs(next,g,flag)==false) return false;
        }
        flag[i]=-1;
        ans.push_back(i);
        return true;
    }
};