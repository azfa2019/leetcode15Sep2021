class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int n=nums.size();
    int left=0,right=n-1;
    while(left<right){
      int mid=left+(right-left+1)/2;
      if(nums[mid]>target) right=mid-1;
      else left=mid;
    }
    return nums[left]==target?left:-1;
  }
};