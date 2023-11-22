class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size(),m=nums[0].size();
        map<int,vector<int>>mp;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++)
                mp[i+j].push_back(nums[i][j]);
        }
        vector<int>res;
        for(auto& [k,v]:mp){
            for(auto val: v)
                res.push_back(val);
        }
        return res;
    }
};