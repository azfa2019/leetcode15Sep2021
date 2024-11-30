class Solution {
    map<int,int>deg;
    map<int,vector<int>>mp;
    vector<vector<int>>ans;
    void dfs(int sn){
        vector<int>&e=mp[sn];
        while(!e.empty()){
            int fn=e.back();
            e.pop_back();
            dfs(fn);
            ans.push_back({sn,fn});
        }
    }
public:
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto&p:pairs){
            mp[p[0]].push_back(p[1]);
            deg[p[0]]--;deg[p[1]]++;
        }
        for(auto it=deg.begin();it!=deg.end();it++)
            if(it->second==-1) 
                dfs(it->first);
        if(ans.empty()) dfs(deg.begin()->first);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};