class Solution {
    vector<int>path;
    vector<vector<int>>ans;
    vector<bool>st;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
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
                if(i && nums[i]==nums[i-1] && !st[i-1]) continue;
                path[u]=nums[i];
                st[i]=true;
                dfs(nums,u+1);
                st[i]=false;
            }
        }
    }
};
