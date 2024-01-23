class Solution {
public:
    int n;
    vector<vector<int>>ans;
    vector<int>path,nums;
    vector<vector<int>> subsets(vector<int>& _nums) {
        nums=_nums;
        n=nums.size();
        dfs(0);
        return ans;
    }
    void dfs(int i){
        ans.push_back(path);
        if(i==n) return;
        for(int j=i;j<n;j++){
            path.push_back(nums[j]);
            dfs(j+1);
            path.pop_back();
        }
    }
};