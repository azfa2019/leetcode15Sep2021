class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        for(auto x:nums){
            int p=abs(x)-1;
            nums[p]=-nums[p];
            if(nums[p]>0) res.push_back(abs(x));
        }
        return res;
    }
};