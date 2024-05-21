class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> nums;
    vector<vector<int>> subsets(vector<int>& _nums) {
        vector<int>path;
        n=_nums.size();
        nums=_nums;
        dfs(0,path);
        return ans;
    }
    void dfs(int cur,vector<int>&path){
        ans.push_back(path);
        if(cur==n) return;
        for(int j=cur;j<n;j++){
            path.push_back(nums[j]);
            dfs(j+1,path);
            path.pop_back();
        }
    }
};