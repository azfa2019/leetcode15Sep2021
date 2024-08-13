class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        dfs(c,0,target);
        return ans;
    }
    void dfs(vector<int>&c,int u,int target){
        if(target==0) {
            ans.push_back(path);
            return;
        }
        if(target<0 || u==c.size()) return;
        
        for(int i=u;i<c.size();i++){
            if(i>u && c[i]==c[i-1]) continue;
            int tmp=target-c[i];
            if(tmp<0) return;
            path.push_back(c[i]);
            dfs(c,i+1,tmp);
            path.pop_back();
        }
    }
};