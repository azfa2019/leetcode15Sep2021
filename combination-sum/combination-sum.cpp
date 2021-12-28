class Solution {
    vector<vector<int>>ans;
    vector<int> candidates;
    int n;
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this-> n=candidates.size();
        this->candidates=candidates;
        vector<int>cur;
        dfs(0,cur,target);
        return ans;
    }
    void dfs(int idx,vector<int>&cur,int target){
        if(target<0) return;
        if(target==0) {
            ans.push_back(cur);
            return;
        }
        for(int i=idx;i<n;i++){
            cur.push_back(candidates[i]);
            dfs(i,cur,target-candidates[i]);
            cur.pop_back();
        }
    }
};