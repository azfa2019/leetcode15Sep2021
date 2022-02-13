class Solution {
    vector<vector<int>>ans;
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>cur;
        dfs(nums,cur,0);
        return ans;
    }
    void dfs(vector<int>&nums,vector<int>&cur,int idx){
        if(idx==nums.size()) {
            ans.push_back(cur);
            return;
        }
        dfs(nums,cur,idx+1);
        cur.push_back(nums[idx]);
        dfs(nums,cur,idx+1);
        cur.pop_back();
    }
};
