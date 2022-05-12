class Solution {
    vector<vector<int>>ans;
    vector<bool>st;
    vector<int>path;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        st=vector<bool>(nums.size());
        path=vector<int>(nums.size());
        dfs(nums,0);
        return ans;
    }
    void dfs(vector<int>&nums,int u){
        if(u==nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!st[i]){
                st[i]=true;
                path[u]=nums[i];
                dfs(nums,u+1);
                st[i]=false;
            }
        }
    }
};