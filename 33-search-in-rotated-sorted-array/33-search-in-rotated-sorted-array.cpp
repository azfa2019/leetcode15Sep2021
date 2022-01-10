class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>nums[l]){
                if(nums[mid]>=target && target>=nums[l]) r=mid;
                else l=mid+1;
            }else{
                if(nums[mid+1]<=target && target<=nums[r]) l=mid+1;
                else r=mid;
            }
        }
        return nums[l]==target?l:-1;
    }
};
// 4,5,6,7,0,1,2
//     t m
// 4,5,6,7,8,1,2
//       m t
// 7,0,1,2,4,5,6
//       m t
// 7,0,1,2,4,5,6
//     t m  
// 0,1,2,4,5,6,7
//     t m  
// 0,1,2,4,5,6,7
//       m t
// 