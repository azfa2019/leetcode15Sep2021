class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        int res=-1;
        while(l<r){
            if(nums[l]+nums[r]>=k) r--;
            else {
                res=max(res,nums[l]+nums[r]);
                l++;
            }
        }
        return res;
    }
};