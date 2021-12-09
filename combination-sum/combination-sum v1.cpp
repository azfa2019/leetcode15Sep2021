class Solution {
    vector<vector<int>>ans;
    int n;
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->n=candidates.size();
        vector<int>cur;
        dfs(0,cur,candidates,target);
        return ans;
    }
    void dfs(int idx,vector<int>&cur,vector<int>& candidates,int remain){
        if(remain<0) return;
        if(remain==0) ans.push_back(cur);
        for(int i=idx;i<n;i++){
            cur.push_back(candidates[i]);
            dfs(i,cur,candidates,remain-candidates[i]); 
            cur.pop_back();
        }
    }
};
