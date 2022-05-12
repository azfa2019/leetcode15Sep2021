class Solution {
    vector<bool>st;
    vector<vector<int>>ans;
    vector<int>path;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path=vector<int>(nums.size());
        st=vector<bool>(nums.size());
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
                path[u]=nums[i];
                st[i]=true;
                dfs(nums,u+1);
                st[i]=false;
            }
        }
    }
};