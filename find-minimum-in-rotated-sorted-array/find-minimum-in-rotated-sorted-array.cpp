class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[right]) right=mid;
            else left=mid+1;
        }
        return nums[left];
    }
};
// 3,4,5,1,2
// rotate at right, nums[mid]>nums[right]
// left=mid+1, else right=mid
// nums[mid]<nums[right] right=mid
// 6 8 0 1 3 4 5
// rotate at left, nums[mid]<nums[right]
// right=mid, else left=mid+1
// 1 2 3 4 5
// no rotate, nums[mid]<nums[right]
// right=mid else left=mid+1