class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int m=l+r>>1;
            if(nums[m]>nums[r]){
                if(nums[m]>=target && target>=nums[l]) r=m;
                else l=m+1;
            }else if(nums[m+1]<nums[r]){
                if(nums[m+1]<=target && target<=nums[r]) l=m+1;
                else r=m;
            }else {
                if(target==nums[r]) return true;
                else r--;
            }
        }
        return nums[l]==target;
    }
};