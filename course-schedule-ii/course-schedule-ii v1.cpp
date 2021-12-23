class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int>inDegree;
        for(int i=0;i<numCourses;i++) inDegree[i]=0;
        unordered_map<int,vector<int>>g;
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        queue<int>source;
        for(auto e:inDegree){
            if(e.second==0) source.push(e.first);
        }
        vector<int>ans;
        while(!source.empty()){
            int cur=source.front();source.pop();
            ans.push_back(cur);
            for(int next:g[cur]){
                inDegree[next]--;
                if(inDegree[next]==0) source.push(next);
            }
        }
        if(ans.size()==numCourses) return ans;
        else return {};
    }
};
