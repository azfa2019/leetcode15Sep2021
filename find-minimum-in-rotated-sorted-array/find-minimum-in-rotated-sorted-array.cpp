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
// 3 4 5 1 2
//     m
//  5 1 2 3 4
//.     m
// 1 2 3 4 5
//.    m
//class Solution {
//public:
//    int findMin(vector<int>& nums) {//00
//        //the pivot has this featuree: the pivot is smaller than the previous number
//        int n=nums.size();
//        int start=0,end=n-1;
//        while(start<=end){
//            int mid=start+(end-start)/2;
//            if(mid>start && nums[mid]<nums[mid-1]) return nums[mid];
//            if(mid<end && nums[mid+1]<nums[mid]) return nums[mid+1];
//            if(nums[mid]>nums[start]) start=mid+1;//left side is sorted, the pivot is on the right
//            else end=mid-1;
//        }
//        return nums[0];
//    }
//};