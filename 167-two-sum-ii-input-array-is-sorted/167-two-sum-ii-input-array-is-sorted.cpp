class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int s=nums[l]+nums[r];
            if(s<target) l++;
            else if(s>target) r--;
            else break;
        }
        return {l+1,r+1};
    }
};