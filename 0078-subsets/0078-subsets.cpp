class Solution {
public:
    int n;
    vector<vector<int>>ans;
    vector<int> nums;
    void dfs(vector<int>& path,int cur){
        ans.push_back(path);
        if(cur==n) return;
        for(int j=cur;j<n;j++){
            path.push_back(nums[j]);
            dfs(path,j+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& _nums) {
        nums=_nums;
        n=nums.size();
        vector<int>path;
        dfs(path,0);
        return ans;
    }

};