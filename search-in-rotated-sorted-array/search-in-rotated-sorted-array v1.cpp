class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[left]){
                if(nums[mid]>=target && target>=nums[left]) right=mid;
                else left=mid+1;
            }else{
                if(nums[mid+1]<=target && target<=nums[right]) left=mid+1;
                else right=mid;
            }
        }
        return nums[left]==target?left:-1;
    }
};
//left=0,right=1
// mid=0
//
// 5,6,7,8,9,0,1
//.  t   m
//nums[m]>t, r=m-1
// else l=m
// 0,1,2,4,5,6,7
//.  t   m
//nums[m]>t, r=m-1
// else l=m
// 8,9,0,1,2,3,4
//   t   m
// need to decide if left is mono or right is mono
// 8,9,0,1,2,3,4
//       m   t
// nums[mid]<t, left=mid+1;
// else right=mid
