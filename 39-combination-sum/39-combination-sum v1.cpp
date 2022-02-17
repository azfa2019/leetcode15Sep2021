class Solution {
    vector<vector<int>>ans;
    vector<int>candidates;
    int n;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates=candidates;
        this->n=candidates.size();
        vector<int>cur;
        dfs(cur,target,0);
        return ans;
    }
    void dfs(vector<int>&cur,int target,int idx){
        if(target<0) return;
        if(target==0) {
            ans.push_back(cur);
            return;
        }
        for(int i=idx;i<n;i++){
            cur.push_back(candidates[i]);
            dfs(cur,target-candidates[i],i);
            cur.pop_back();
        }
    }
};
