class Solution {
public:
    int findMin(vector<int>& nums) {
      int n=nums.size();
      // 4 5 6 7 0 1 4  nums[mid]>nums[left] left=mid+1, search on right
      // 0 1 4 4 5 6 7  nums[mid]>nums[left] left=mid+1, search on left
      // 6 7 0 1 4 5 6 nums[mid]<nums[left] left=mid+1, search left
      
      //compare with right
      // 4 5 6 7 0 1 4  nums[mid]>nums[right] left=mid+1, search on right
      // 0 1 4 4 5 6 7  nums[mid]<nums[right] left=mid+1, search on left
      // 6 7 0 1 4 5 6 nums[mid]<nums[left] left=mid+1, search left
      int left=0,right=n-1;
      while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right]) left=mid+1;
        else if(nums[mid]<nums[right]) right=mid;
        else right--;
      }
      return nums[left];
    }
};