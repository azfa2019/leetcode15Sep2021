class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    int n;
    vector<int>nums;
    vector<vector<int>> subsets(vector<int>& _nums) {
        nums=_nums;
        n=nums.size();
        dfs(0);
        return res;
    }
    void dfs(int idx){
        if(idx==n) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[idx]);//选
        dfs(idx+1);
        path.pop_back();
        dfs(idx+1); //不选
        }
};